#include <globaldefs.h>

extern "C" void func_02059cfc(unsigned char* elem, int arg1, int idx);

struct Struct_020579b4 {
    int f0;                       // 0x0
    int f4;                       // 0x4
    unsigned char arr[16][0xd4];  // 0x8 ..
};

// USA: func_020579b4
extern "C" ARM void func_020579b4(Struct_020579b4* p, int arg1) {
    int i;
    for (i = 0; i < 16; i++) {
        func_02059cfc(p->arr[i], arg1, i + 0xd0);
    }
}
