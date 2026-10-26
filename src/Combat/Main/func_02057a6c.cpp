#include <globaldefs.h>

extern "C" void func_02059f54(void* elem, int idx);

struct Struct_02057a6c_2 {
    char pad0[0xb2];
    short flag;                 // 0xb2
    char pad1[0x18];            // 0xb4..0xcb
    unsigned char b0 : 1;       // 0xcc bit0
    unsigned char b1 : 1;       // bit1 (0x2)
    unsigned char b2 : 1;
    unsigned char b3 : 1;
    unsigned char unknown_cc_4_ : 1;
    unsigned char unknown_cc_5_ : 1;
    unsigned char unknown_cc_6_ : 1;
    unsigned char unknown_cc_7_ : 1;
    char pad2[7];               // 0xcd..0xd3
};

struct Struct_02057a6c {
    char hdr[8];
    struct Struct_02057a6c_2 elems[16];
};

// USA: func_02057a6c
extern "C" ARM void func_02057a6c(struct Struct_02057a6c* c) {
    int i;
    for (i = 0; i < 16; i++) {
        if (c->elems[i].b1) {
            func_02059f54(&c->elems[i], i + 0xd0);
        }
    }
}
