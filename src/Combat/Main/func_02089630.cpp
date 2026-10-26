#include <globaldefs.h>
#include "Util/Random.h"

struct Struct_02082828;
extern "C" void func_02082d38(struct Struct_02082828* dst, struct Struct_02082828* src);

extern "C" void func_020891cc(void* dst, void* src, int arg2);

struct Struct_02089630 {
    unsigned int fieldA : 10;
    unsigned int fieldB : 10;
    unsigned int fieldC : 10;
    unsigned int unknown_3_6_ : 2;
};

// USA: func_02089630
extern "C" ARM void func_02089630(char* dst, char* src, int arg2) {
    func_020891cc(dst, src, arg2);
    struct Random* rng = GetBTRandom();

    if (arg2 != 0) {
        unsigned short var1 = *(unsigned short*)(src + 0x30);
        *(unsigned short*)(dst + 0x4) = var1;
        *(unsigned short*)(dst + 0x0) = var1;
    } else {
        unsigned int base = *(unsigned short*)(src + 0x30);
        *(unsigned short*)(dst + 0x4) = (unsigned short)(unsigned int)(0.5f +
            (float)base * NextRandomFloatBetween(rng, 0.8f, 1.0f));
        *(unsigned short*)(dst + 0x0) = *(unsigned short*)(dst + 0x4);
    }
    unsigned short second = *(unsigned short*)(src + 0x32);
    *(unsigned short*)(dst + 0x6) = second;
    *(unsigned short*)(dst + 0x2) = second;
    *(unsigned short*)(dst + 0xc) = *(unsigned short*)(src + 0x38);
    *(unsigned short*)(dst + 0x8) = *(unsigned short*)(src + 0x34);
    *(unsigned short*)(dst + 0xa) = *(unsigned short*)(src + 0x36);
    ((Struct_02089630*)(dst + 0x10))->fieldA = (unsigned short)((Struct_02089630*)(src + 0x3c))->fieldA;
    ((Struct_02089630*)(dst + 0x10))->fieldB = (unsigned short)((Struct_02089630*)(src + 0x3c))->fieldB;
    ((Struct_02089630*)(dst + 0x10))->fieldC = (unsigned short)((Struct_02089630*)(src + 0x3c))->fieldC;
    func_02082d38((struct Struct_02082828*)(dst + 0x3e), (struct Struct_02082828*)(src + 0x40));
}
