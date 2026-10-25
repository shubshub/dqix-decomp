#include <globaldefs.h>
#include "GameState/GameState.h"

int GetFieldAt0x150_02053c6c(unsigned char* obj);
extern "C" void PartyMember_RecalculateStats(void* a, int arg2);

struct Struct_02084a64 {
    unsigned int unknown_0_0_ : 10;
    unsigned int unknown_1_2_ : 10;
    unsigned int unknown_2_4_ : 10;
    unsigned int : 2;
};

struct Struct_ov017_021ce8ac {
    unsigned int unknown_0_0_ : 10;
    unsigned int unknown_1_2_ : 3;
    unsigned int unknown_1_5_ : 19;
};

struct Struct_ov017_021ce8ac_2 {
    char unknown_0_[4];
    Struct_02084a64 unknown_4_;
    Struct_02084a64 unknown_8_;
    Struct_02084a64 unknown_c_;
    Struct_ov017_021ce8ac unknown_10_;
};

// USA: func_ov017_021ce8ac
extern "C" ARM void func_ov017_021ce8ac(int arg0, Struct_ov017_021ce8ac_2* arg1, GameState* arg2) {
    GameObject* var0 = func_0200ff1c(arg2, arg1->unknown_10_.unknown_1_2_);
    if (!var0) return;
    unsigned char* var1 = (unsigned char*)func_02053c6c((unsigned char*)var0);
    if (!var1) return;
#if defined(jpn)
    Struct_02084a64* var2 = (Struct_02084a64*)(var1 + 0x884);
#else
    Struct_02084a64* var2 = (Struct_02084a64*)(var1 + 0x91c);
#endif
    stats[0].f0 = src->w0.f0;
    stats[0].f1 = src->w0.f1;
    stats[0].f2 = src->w0.f2;
    stats[1].f0 = src->w1.f0;
    stats[1].f1 = src->w1.f1;
    stats[1].f2 = src->w1.f2;
    stats[2].f0 = src->w2.f0;
    stats[2].f1 = src->w2.f1;
    stats[2].f2 = src->w2.f2;
    stats[3].f0 = src->w3.f0;
    PartyMember_RecalculateStats(p, 0);
}
