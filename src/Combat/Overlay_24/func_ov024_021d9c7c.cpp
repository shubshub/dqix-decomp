#include <globaldefs.h>
#include "Util/Random.h"

extern "C" void* func_ov000_02153710(void*, short);
extern "C" int func_ov000_02159dbc(void*, short);

struct Struct_ov024_021d9c7c { struct Random* rng; };

// USA: func_ov024_021d9c7c
extern "C" ARM int func_ov024_021d9c7c(struct Struct_ov024_021d9c7c* holder, unsigned short category, int unused1, int arg3, int arg4, int arg5) {
#if defined(jpn)
 enum {regionalOffset=0x8b8};
#else
 enum {regionalOffset=0x950};
#endif
    int inRange = 0;
    if (category <= 3) {
        inRange = 1;
    }
    float value;
    if (inRange) {
        char* base = (char*)func_ov000_02153710(holder->rng, (short)category);
        if (base == NULL) {
            return arg5;
        }
        int idx = *(int*)(base + regionalOffset);
        unsigned short v = *(unsigned short*)(base + idx * 2 + 0x16c);
        value = v;
    } else {
        int v = func_ov000_02159dbc(holder->rng, (short)category);
        value = v;
    }
    struct Random* rng = holder->rng;
    float var7 = NextRandomFloatBetween(rng, 0.9f, 1.1f);
    float a = (50.0f + 5.0f * value) * var7;
    float var9 = NextRandomFloatBetween(rng, 0.9f, 1.1f);
    float b = 200.0f * var9;
    if (a < b) {
        a = b;
    }
    return (int)a;
}
