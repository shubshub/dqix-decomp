#include <globaldefs.h>
#include "NitroSDK/Cache.h"

extern "C" int func_0204a5e4(int a, int b);

struct Struct_0204fbf8 {
    char pad[0x1c];
    unsigned char lo : 4;
    unsigned char hi : 4;
};

struct Struct_0204fbf8_2 {
    char pad0[0x4];
    struct Struct_0204fbf8* field4;
    void* field8;
    char pad1[0xa0 - 0xc];
    int unknown_a0_;
    int unknown_a4_;
};

// USA: func_0204fbf8
extern "C" ARM void func_0204fbf8(Struct_0204fbf8_2* a) {
    unsigned char hi = a->field4->hi;
    unsigned char lo = a->field4->lo;
    unsigned char var2[2];
    var2[0] = lo;
    var2[1] = hi;
    void (*fp)(void*, int, unsigned int) = (void(*)(void*, int, unsigned int))func_0204a5e4(var2[0], var2[1]);
    CleanInvalidateCacheRange(a->field8, a->unknown_a4_);
    fp(a->field8, a->unknown_a0_, a->unknown_a4_);
}
