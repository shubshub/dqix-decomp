#include <globaldefs.h>

struct Struct_0209ab20_2 { unsigned short a; unsigned short b; };
struct Struct_0209ab20_3 {
    unsigned char pad0[0xc];
    struct Struct_0209ab20_2 pairs[17];
};
struct Struct_0209ab20 {
    unsigned char unknown_0_[0x100];
    struct Struct_0209ab20_3 slots[13];
    unsigned char unknown_510_[0xc];
    int counts[16];
};
struct Struct_02086f24_7 {
    struct Struct_0209ab20* base;
};

// USA: func_0209ab20
extern "C" ARM int func_0209ab20(struct Struct_02086f24_7* h, int slot, int threshold, unsigned char* out) {
    int idx;
    int count = 0;
    for (idx = 0; idx < h->base->counts[slot]; idx++) {
        unsigned short b = h->base->slots[slot].pairs[idx].b;
        unsigned short a = h->base->slots[slot].pairs[idx].a;
        if (b <= threshold) {
            out[count] = (unsigned char)a;
            count++;
        }
    }
    return count;
}
