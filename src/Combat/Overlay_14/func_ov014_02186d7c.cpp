#include <globaldefs.h>

struct Struct_0207fcb8;
extern "C" unsigned int func_0207fcb8(Struct_0207fcb8*);
struct Struct_0207fd44_2;
extern "C" unsigned int func_0207fd44(Struct_0207fd44_2*);
struct Struct_0207fd00;
extern "C" unsigned int func_0207fd00(Struct_0207fd00*);
extern "C" unsigned int func_0207fe80(unsigned int, unsigned int, unsigned int, unsigned int);
extern "C" void func_ov014_02186e2c(unsigned int);

// USA: func_ov014_02186d7c
extern "C" ARM void func_ov014_02186d7c(unsigned int self) {
    if (*(unsigned char*)((char*)self + 0x17a) != 0) {
        func_0207fcb8((Struct_0207fcb8*)(*(unsigned int*)((char*)self + 0xc0)));
        func_0207fd00((Struct_0207fd00*)(*(unsigned int*)((char*)self + 0xc0)));
        func_0207fe80(*(unsigned int*)((char*)self + 0xc0), 1, 0, 1);
        func_0207fd44((Struct_0207fd44_2*)(*(unsigned int*)((char*)self + 0xc0)));
        func_ov014_02186e2c(self);
    }
}
