#include <globaldefs.h>
#include "GameState/GameState.h"

extern "C" void* func_ov017_021b8468(void* p);
extern "C" void* func_ov017_021b8470(void* obj);
extern "C" void func_ov000_02160fa8(void* work, int mask);
extern "C" GameObject* func_0200ff1c(GameState* bs, int id);
extern "C" int func_02053c6c(unsigned char* obj);

struct Struct_ov017_021c8588 {
    unsigned int lo : 30;
    unsigned int flag : 1;
    unsigned int hi : 1;
};

// USA: func_ov017_021c8588
extern "C" ARM void func_ov017_021c8588(int a, signed char* b, GameState* bs, char* d) {
#if defined(jpn)
 enum {regionalOffset0=0x3508, regionalOffset1=0x8b4};
#else
 enum {regionalOffset0=0x3718, regionalOffset1=0x94c};
#endif
    void* handle;
    signed char* p0;
    int i;
    void* inner = *(void**)(d + regionalOffset0);
    handle = func_ov017_021b8468(inner);
    if (handle == 0) return;
    if (func_ov017_021b8470(inner) == 0) return;

    p0 = b + 4;
    for (i = 0; i < 4; i++) {
        GameObject* combatant = func_0200ff1c(bs, i);
        if (combatant == 0) continue;
        int field150 = func_02053c6c((unsigned char*)combatant);
        if (field150 == 0) continue;
        signed char v0 = p0[i];
        signed char v1 = *(p0 + i + 4);
        if (v0 >= 0) *(int*)((char*)field150 + regionalOffset1) = v0;
        if (v1 < 0) continue;
        ((Struct_ov017_021c8588*)((char*)field150 + 0x78))->flag = (unsigned short)v1;
    }

    if (*((unsigned char*)inner + 3) != 0 && handle != 0) {
        func_ov000_02160fa8(handle, 0x4000000 << a);
    }
}
