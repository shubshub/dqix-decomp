#include <globaldefs.h>
#include "GameState/GameState.h"

extern "C" GameObject* func_0200ff1c(GameState* battleStruct, int combatantId);
extern "C" int func_02053c6c(unsigned char* obj);
extern "C" void* LinkMessageQueue_GetInstance(void);
extern "C" void func_0205e330(void* a, void* b, int c);

struct Struct_ov017_021ccc34 {
    unsigned char tag;
    unsigned char pad0[3];
    unsigned char unknown_4_0_ : 3;
    unsigned char unknown_4_3_ : 1;
    unsigned char rest : 4;
    unsigned char data[15];
};

struct Struct_ov017_021ccc34_2 {
    char pad[0x464];
    unsigned char b;
};

// USA: func_ov017_021ccc34
extern "C" ARM void func_ov017_021ccc34(int combatantId) {
    GameState* bs = GameState::GetInstance();
    GameObject* c = func_0200ff1c(bs, combatantId);
    if (!c) return;
    int field150 = func_02053c6c((unsigned char*)c);
    if (!field150) return;

    void* p = LinkMessageQueue_GetInstance();
    struct Struct_ov017_021ccc34 buf;
    unsigned char x = (unsigned char)combatantId;
    buf.tag = 0xe;
    buf.unknown_4_0_ = x;
    buf.unknown_4_3_ = 0;
    int i;
    for (i = 0; i < 15; i++) {
        buf.data[i] = *(unsigned char*)((char*)field150 + 0x464 + i);
    }
    func_0205e330(p, &buf, 0);

    buf.unknown_4_3_ = 1;
    for (i = 0; i < 12; i++) {
        struct Struct_ov017_021ccc34_2* p2 = (struct Struct_ov017_021ccc34_2*)((char*)field150 + (i + 15));
        buf.data[i] = p2->b;
    }
    func_0205e330(p, &buf, 0);
}
