#include <globaldefs.h>

extern "C" void func_02059cc8(unsigned char* obj);

struct Struct_02057930 {
    int f0;                       // 0x0
    int f4;                       // 0x4
    unsigned char arr[16][0xd4];  // 0x8 .. 0xd48
    int unknown_d48_;                     // 0xd48
    int unknown_d4c_;                     // 0xd4c
    int unknown_d50_;                     // 0xd50
};

// USA: func_02057930
extern "C" ARM void func_02057930(Struct_02057930* p) {
    int i;
    p->f0 = 0;
    p->f4 = 0;
    p->unknown_d4c_ = 0;
    p->unknown_d50_ = 0;
    for (i = 0; i < 16; i++) {
        func_02059cc8(p->arr[i]);
    }
    p->unknown_d48_ = 0;
}
