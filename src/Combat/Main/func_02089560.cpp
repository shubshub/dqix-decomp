#include <globaldefs.h>

struct Struct_02082828;
extern "C" void func_02082d38(struct Struct_02082828* dst, struct Struct_02082828* src);

struct Struct_02089560 {
    unsigned int fieldA : 10;
    unsigned int fieldB : 10;
    unsigned int fieldC : 10;
    unsigned int unknown_3_6_ : 2;
};

// USA: func_02089560
extern "C" ARM void func_02089560(char* dst, char* buf, char* src) {
    *(dst + 0x25) = 0;
    *(dst + 0x38) = 0;
    func_02082d38((struct Struct_02082828*)(dst + 0x3e), (struct Struct_02082828*)(buf + 0x9));
    *(unsigned short*)(dst + 0xc) = *(unsigned short*)(src + 0x38);
    *(unsigned short*)(dst + 0x8) = *(unsigned short*)(src + 0x34);
    *(unsigned short*)(dst + 0xa) = *(unsigned short*)(src + 0x36);
    ((Struct_02089560*)(dst + 0x10))->fieldA = (unsigned short)((Struct_02089560*)(src + 0x3c))->fieldA;
    ((Struct_02089560*)(dst + 0x10))->fieldB = (unsigned short)((Struct_02089560*)(src + 0x3c))->fieldB;
    ((Struct_02089560*)(dst + 0x10))->fieldC = (unsigned short)((Struct_02089560*)(src + 0x3c))->fieldC;
    *(dst + 0x26) = 1;
}
