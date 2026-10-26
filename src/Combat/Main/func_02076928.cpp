#include <globaldefs.h>

extern int data_02114e50;

struct Struct_02076080 {
    char pad0[0x20];
    int* unknown_20_;           // 0x20
    char pad1[0x30];    // 0x24..0x53
    int unknown_54_;            // 0x54
    char pad2[0x7];     // 0x58..0x5e
    unsigned char unknown_5f_;  // 0x5f
    int f60;            // 0x60
    int f64;            // 0x64
    int f68;            // 0x68
    int f6c;            // 0x6c
};

// USA: func_02076928
extern "C" ARM void func_02076928(struct Struct_02076080* s, int val) {
    int* base;
    if (s->unknown_5f_ == 0) return;
    if (s->unknown_54_ <= 0) return;
    if (s->f64 == val || val == 0) return;
    s->f60 = 0;
    s->f64 = val;
    s->f68 = data_02114e50;
    base = s->unknown_20_;
    s->f6c = ((int*)base[s->f64])[s->f60];
}
