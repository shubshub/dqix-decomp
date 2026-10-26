#include <globaldefs.h>

struct Struct_02081818 {
    char pad0[6];
    short x;    // 0x6
    short y;    // 0x8
    short a;    // 0xa
    short b;    // 0xc
    char pad1[5];
    unsigned char lo4 : 4;   // 0x13 bits[3:0]
    unsigned char unknown_13_4_ : 4;   // 0x13 bits[7:4]
};

extern "C" void func_0204f914(void*, int, int, int, int, int);

// USA: func_02081818
extern "C" ARM void func_02081818(int unused, void* ctx, Struct_02081818* s) {
    func_0204f914(ctx, s->unknown_13_4_, s->x, s->y,
        (short)(s->x + s->a), (short)(s->y + s->b));
}
