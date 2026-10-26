#include <globaldefs.h>
#include "GameState/GameState.h"

extern "C" int func_02053c6c(unsigned char* obj);
extern "C" void PartyMember_RecalculateStats(void* a, int arg1);

struct Struct_02084a64 {
    unsigned int f0 : 10;
    unsigned int f1 : 10;
    unsigned int f2 : 10;
    unsigned int : 2;
};

struct Struct_ov017_021ce8ac {
    unsigned int f0 : 10;
    unsigned int id : 3;
    unsigned int rest : 19;
};

struct Struct_ov017_021ce8ac_2 {
    char pad[4];
    Struct_02084a64 unknown_4_;
    Struct_02084a64 w1;
    Struct_02084a64 w2;
    Struct_ov017_021ce8ac unknown_10_;
};

// USA: func_ov017_021ce8ac
extern "C" ARM void func_ov017_021ce8ac(int unused0, Struct_ov017_021ce8ac_2* src, GameState* battleStruct) {
    GameObject* c = func_0200ff1c(battleStruct, src->unknown_10_.id);
    if (!c) return;
    unsigned char* p = (unsigned char*)func_02053c6c((unsigned char*)c);
    if (!p) return;
#if defined(jpn)
    Struct_02084a64* stats = (Struct_02084a64*)(p + 0x884);
#else
    Struct_02084a64* stats = (Struct_02084a64*)(p + 0x91c);
#endif
    stats[0].f0 = src->unknown_4_.f0;
    stats[0].f1 = src->unknown_4_.f1;
    stats[0].f2 = src->unknown_4_.f2;
    stats[1].f0 = src->w1.f0;
    stats[1].f1 = src->w1.f1;
    stats[1].f2 = src->w1.f2;
    stats[2].f0 = src->w2.f0;
    stats[2].f1 = src->w2.f1;
    stats[2].f2 = src->w2.f2;
    stats[3].f0 = src->unknown_10_.f0;
    PartyMember_RecalculateStats(p, 0);
}
