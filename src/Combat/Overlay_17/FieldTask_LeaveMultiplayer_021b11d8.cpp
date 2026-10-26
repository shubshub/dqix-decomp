#include <globaldefs.h>
#include "Combat/SearchEntry.h"
#include "GameState/GameState.h"
#include "Resource/GameResources.h"

struct SearchStruct;
struct SearchStruct0202c1a4;

struct SearchStruct {
    char unk0[0xfc0];
    int busy;
};

struct Struct_ov017_021b11d8 {
    char data[6];
    signed char owner;
    unsigned char unknown_7_;
    unsigned char f8;
    signed char unknown_9_;
};

struct Struct_ov017_021b11d8_2 {
    unsigned char pad0[1];
    unsigned char flag1;
    unsigned char pad2[6];
    unsigned char mode;
    unsigned char count;
    unsigned char flags;
    unsigned char unknown_b_;
    unsigned short timer;
};

extern "C" void* LinkSession_GetInstance(void);
extern "C" void func_ov017_021c37a4(void);
extern "C" void func_ov017_021d1118(int a, int b, int c, int d);
extern "C" void func_ov017_021d1014(int a, int b, int c);
extern "C" void func_ov017_021d0b30(int a, int b, int c);
extern "C" void func_ov017_021d1810(int, int, signed char);
extern "C" int func_0202c660(SearchStruct* obj, int value);
extern "C" int LinkSession_IsSlotMember(SearchStruct* obj, int index);
extern "C" int LinkSession_IsSlotConnected(SearchStruct* obj, int index);
extern "C" int func_0202c648(int* obj);
extern "C" signed char LinkSession_GetOwnSlot(SearchStruct0202c1a4* obj);
extern "C" int GameState_GetProtagonistIndex(GameState* battleStruct);
extern "C" int func_ov017_02195658(GameResources* res);

// Overlay 17, originally func_ov017_021b11d8 (USA/EUR 0x021b11d8, JPN 0x021b1864)
extern "C" ARM void FieldTask_LeaveMultiplayer(void* obj, void* node) {
    Struct_ov017_021b11d8_2* self = (Struct_ov017_021b11d8_2*)obj;
    GameState* gs = GameState::GetInstance();
    GameResources* res = GetGameResources();
    SearchStruct* search = (SearchStruct*)LinkSession_GetInstance();
    unsigned char mode = self->mode;
    if (mode == 0) {
        self->count = (unsigned char)LinkSession_GetOwnSlot((SearchStruct0202c1a4*)search);
        self->flags = 0;
        for (int i = 0; i < 4; i++) {
            if (i != self->count) {
                if (LinkSession_IsSlotMember(search, i) != 0) {
                    self->flags |= (1 << i);
                }
            }
        }
        func_ov017_021d1810(2, -1, (signed char)GameState_GetProtagonistIndex(gs));
        func_ov017_021d1118(-1, 1, 1, 2);
        func_ov017_021d1014(-1, 1, 0);
        self->mode++;
        return;
    }
    if (mode == 1) {
#if defined(jpn)
        Struct_ov017_021b11d8* slot = (Struct_ov017_021b11d8*)((char*)GameState::GetInstance() + 0x7280);
#else
        Struct_ov017_021b11d8* slot = (Struct_ov017_021b11d8*)((char*)GameState::GetInstance() + 0x74c0);
#endif
        for (int i = 0; i < 3; i++, slot++) {
            if (slot->owner < 4) {
                continue;
            }
            if (slot->unknown_7_ != 0 || slot->f8 != 0) {
                return;
            }
            if (slot->unknown_9_ >= 0) {
                return;
            }
        }
        self->mode++;
        return;
    }
    if (mode == 2) {
        func_ov017_021d0b30(9, 0, 0);
        func_0202c660(search, 0);
        self->mode++;
        return;
    }
    if (mode != 3) {
        return;
    }
    if (func_0202c648((int*)search) != 0) {
        goto done;
    }
    {
        int slot = func_ov017_02195658(res);
        if (slot > 0) {
            self->flags &= ~(1 << slot);
        }
    }
    if (search->busy == 0) {
        for (int i = 1; i < 4; i++) {
            if ((self->flags & (1 << i)) != 0) {
                if (LinkSession_IsSlotConnected(search, i) == 0) {
                    self->flags &= ~(1 << i);
                }
            }
        }
    }
    for (int i = 0; i < 4; i++) {
        if ((self->flags & (1 << i)) != 0) {
            SearchEntry0202c178* e = LinkSession_GetReceivedRecord(search, i);
            if (e == 0) {
                continue;
            }
            int bit = 1 << self->count;
            unsigned short m = e->members;
            if ((m & bit) != 0) {
                return;
            }
        }
    }
    if (self->timer >= 0x3e8) {
        goto done;
    }
    if (search->busy != 0) {
        return;
    }
    self->timer += gs->GetEffectiveDeltaTime();
    return;
done:
    func_ov017_021c37a4();
    self->flag1 = 1;
}
