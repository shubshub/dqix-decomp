#include <globaldefs.h>

#if defined(jpn)
enum { Enum_02027b5c_2712 = 0x9cc };
#else
enum { Enum_02027b5c_2712 = 0xa98 };
#endif

struct Struct_02027b5c {
    unsigned short h0;
    unsigned char b2;
    int w4;
    int w8;
};

struct Struct_0201f3b4 {
    char pad[Enum_02027b5c_2712];
    unsigned char capacity;
    unsigned char count;
    char pad2[2];
    struct Struct_02027b5c* base;
};

// USA: func_02027b5c
extern "C" ARM void func_02027b5c(struct Struct_0201f3b4* c, unsigned short h, unsigned char b, int w4, int w8) {
    struct Struct_02027b5c* base = c->base;
    struct Struct_02027b5c* dst;
    if (base == NULL) return;
    if (c->capacity <= c->count) return;
    dst = &base[c->count];
    dst->h0 = h;
    dst->b2 = b;
    dst->w4 = w4;
    dst->w8 = w8;
    c->count++;
}
