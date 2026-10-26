#include <globaldefs.h>

struct Elem_0205d81c {
    char pad0[0xc2];
    unsigned short unknown_c2_;
    char pad1[0xe0 - 0xc4];
};

struct Struct_0205d81c {
    char pad0[0x98];
    int field98;
    struct Elem_0205d81c* unknown_9c_;
    char pad1[0xe0 - 0xa0];
};

extern "C" struct Elem_0205d81c* func_0205d81c(struct Struct_0205d81c*, int);

// Main, originally SetElementFieldC2_0205deb4 (USA 0x0205deb4, EUR 0x0205dec4, JPN 0x0205f1c8)
extern "C" ARM void Window_SetPanePalette(struct Struct_0205d81c* s, int key, int value) {
    struct Elem_0205d81c* e;
    if (s->field98 == 0 || s->unknown_9c_ == 0) return;
    e = func_0205d81c(s, key);
    if (e != 0) {
        unsigned short nibble = value & 0xf;
        e->unknown_c2_ = nibble & 0xf;
    }
}
