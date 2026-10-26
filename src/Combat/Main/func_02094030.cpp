#include <globaldefs.h>
#include "GameState/GameState.h"
#include "std_library_functions.h"
#include "Resource/GameResources.h"

struct Struct_02093b54 {
#if defined(jpn)
    char data[0xb];
#else
    char data[0x30];
#endif
};

struct Struct_02093ad8 {
    struct Struct_02093b54 payload;
#if defined(jpn)
    unsigned char unknown_b_;
#endif
    short unknown_30_;
    signed char partySlot;
    unsigned char flags;
};

struct Struct_02094030 {
    struct Struct_02093ad8 records[8];
#if defined(jpn)
    char pad0[0x13b - 0x80];
#else
    char pad0[0x3cb - 0x1a0];
#endif
    signed char count;
    char pad1[0x3cd - 0x3cc];
    unsigned char flags;
};

extern "C" void func_02093980(char* obj);
extern "C" void func_02093b54(struct Struct_02093ad8* dst, struct Struct_02093ad8* src);
extern "C" int func_0209372c(int x);
extern "C" void* LinkSession_GetInstance(void);
extern "C" int LinkSession_IsGuest(void* obj);

// USA: func_02094030

extern "C" ARM int func_02094030(struct Struct_02094030* queue, int arg1, int arg2, int slot) {
    GameObject* combatant = GameState::GetInstance()->GetPartyMemberByIndex(slot);
    void* ctx = LinkSession_GetInstance();
    GameResources* var2 = GetGameResources();

    if (LinkSession_IsGuest(ctx) != 0) {
        if (arg1 == 10000) return 1;
    }
    if (queue->count >= 8) return 1;

    struct Struct_02093ad8* request = &queue->records[queue->count];
    func_02093980((char*)request);

    if (combatant == 0 || arg1 == 3) {
        char* name = var2->partyNames[slot];
        if (name[0] == 0) return 1;
        sprintf(request->payload.data, name);
    } else if (combatant != 0) {
        sprintf(request->payload.data, combatant->baseStats_->name);
    }

    request->unknown_30_ = (short)arg1;
    request->partySlot = (signed char)slot;
    if (queue->count <= 0) {
        queue->flags |= 1;
    }

    unsigned int category = (unsigned int)func_0209372c(request->unknown_30_);
    queue->count++;

    int i;
    for (i = queue->count - 1; i >= 2; i--) {
        if (func_0209372c(queue->records[i - 1].unknown_30_) <= category) break;
        struct Struct_02093ad8 tmp;
        func_02093b54(&tmp, &queue->records[i]);
        func_02093b54(&queue->records[i], &queue->records[i - 1]);
        func_02093b54(&queue->records[i - 1], &tmp);
    }
    return 0;
}
