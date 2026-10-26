#include <globaldefs.h>

struct Struct_02064e88 {
    unsigned char pad0[0xc];
    unsigned int flags;
    unsigned char pad1[0xd8];
};

// USA: func_020984b0
extern "C" ARM void func_020984b0(struct Struct_02064e88* arr) {
    int i;
    for (i = 0; i < 30; i++) {
        unsigned int* p = (unsigned int*)((char*)arr + i * 0xe8);
        p[3] &= ~0x3f000000;
    }
}
