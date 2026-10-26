#include <globaldefs.h>

struct Struct_02114260_4 { void (*fn)(int); int arg; unsigned char count; };
extern struct Struct_02114260_4 data_02114260[];

// USA: func_020d29b0
extern "C" ARM void func_020d29b0(int packed) {
    struct Struct_02114260_4* e = &data_02114260[packed & 0xff];
    if (((packed >> 8) & 0xff) != e->count) return;
    if (e->fn == 0) return;
    e->fn(e->arg);
}
