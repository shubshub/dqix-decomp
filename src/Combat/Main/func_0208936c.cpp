#include <globaldefs.h>

struct Struct_02082828;
extern "C" void func_02082d38(struct Struct_02082828* dst, struct Struct_02082828* src);

extern "C" void func_020891cc(void* dst, void* arg1, void* src2);

struct Struct_0208936c {
    unsigned int fieldA : 10;
    unsigned int fieldB : 10;
    unsigned int fieldC : 10;
    unsigned int unknown_3_6_ : 2;
};

// USA: func_0208936c
extern "C" ARM void func_0208936c(char* dst, char* arg1, char* src2) {
    func_020891cc(dst, arg1, src2);

    *(unsigned short*)(dst + 0x0) = *(unsigned short*)(arg1 + 0x4);
    *(unsigned short*)(dst + 0x2) = *(unsigned short*)(arg1 + 0x6);
    *(unsigned short*)(dst + 0x4) = *(unsigned short*)(src2 + 0x30);
    *(unsigned short*)(dst + 0x6) = *(unsigned short*)(src2 + 0x32);
    func_02082d38((struct Struct_02082828*)(dst + 0x3e), (struct Struct_02082828*)(arg1 + 0x9));

    *(unsigned char*)(dst + 0x24) = *(unsigned char*)(arg1 + 0x8);

    unsigned int var0 = *(unsigned int*)(arg1 + 0x0);
    *(unsigned int*)(dst + 0x14) = var0;
    if (var0 & 0x2) {
        unsigned short v = *(unsigned short*)(dst + 0x22);
        v = (v & ~3) | 1;
        *(unsigned short*)(dst + 0x22) = v;
    }

    unsigned char t = *(unsigned char*)(dst + 0x24);
    if (t != 0) {
        *(unsigned int*)(dst + 0x14) |= 0x800000;
        *(unsigned char*)(dst + 0x24) = t;
    }

    *(unsigned short*)(dst + 0xc) = *(unsigned short*)(src2 + 0x38);
    *(unsigned short*)(dst + 0x8) = *(unsigned short*)(src2 + 0x34);
    *(unsigned short*)(dst + 0xa) = *(unsigned short*)(src2 + 0x36);
    ((Struct_0208936c*)(dst + 0x10))->fieldA = (unsigned short)((Struct_0208936c*)(src2 + 0x3c))->fieldA;
    ((Struct_0208936c*)(dst + 0x10))->fieldB = (unsigned short)((Struct_0208936c*)(src2 + 0x3c))->fieldB;
    ((Struct_0208936c*)(dst + 0x10))->fieldC = (unsigned short)((Struct_0208936c*)(src2 + 0x3c))->fieldC;
    *(unsigned char*)(dst + 0x26) = 1;
}
