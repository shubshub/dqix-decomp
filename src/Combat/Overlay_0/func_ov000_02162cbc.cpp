#include <globaldefs.h>
#include "GameState/GameState.h"

struct Struct_02049efc_2;

struct Struct_ov000_02162cbc_3 {
    char pad0[0x14];
    unsigned int flags;
    char pad18[0x22 - 0x18];
    unsigned short unknown_22_0_ : 2;
    unsigned short unknown_22_2_ : 4;

    unsigned int inline_ov000_02162cbc() { return flags; }
    unsigned char inline_ov000_02162cbc_2() { return unknown_22_2_; }
    unsigned char inline_ov000_02162cbc_3() { return unknown_22_0_; }
};

struct Struct_ov000_02162cbc {
    char pad0[0xc1];
    unsigned char unknown_c1_;
    char unknown_c2_[0x138 - 0xc2];
    Struct_ov000_02162cbc_3* status;
};

struct Struct_ov000_02162cbc_2 {
#if defined(jpn)
    char pad0[0x218];
#else
    char pad0[0x29c];
#endif
    void* unknown_29c_;
};

extern "C" int func_ov000_02153e40(void* obj, short* buf, int max, int start);
extern "C" void func_02049efc(struct Struct_02049efc_2* obj);
extern "C" void func_ov000_02162dc4(Struct_ov000_02162cbc_2* self, GameObject* arg1, Struct_ov000_02162cbc* actor, unsigned int flags,
                                    int arg4, int arg5, unsigned long long mask, int zero);

// USA: func_ov000_02162cbc
extern "C" ARM void func_ov000_02162cbc(Struct_ov000_02162cbc_2* self) {
    GameState* bs = GameState::GetInstance();
    short ids[12];
    int count = func_ov000_02153e40(self->unknown_29c_, ids, 0xc, 0);
    for (int i = 0; i < count; i++) {
        Struct_ov000_02162cbc* c = (Struct_ov000_02162cbc*)bs->GetCombatantByIndex(ids[i]);
        if (!c) continue;
        func_02049efc((struct Struct_02049efc_2*)c);
        if (c->status->flags & 1) continue;
        c->unknown_c1_ &= ~0xf0;
        func_ov000_02162dc4(self, NULL, c, c->status->inline_ov000_02162cbc(), c->status->inline_ov000_02162cbc_2(), c->status->inline_ov000_02162cbc_3(), 0, 0);
    }
}
