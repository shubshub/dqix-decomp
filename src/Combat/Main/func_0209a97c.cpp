#include <globaldefs.h>

struct Pair0209a97c { unsigned short a; unsigned short b; };
struct Struct_0209a97c_3 { struct Pair0209a97c pairs[20]; };
struct Struct_0209a97c_2 {
    unsigned char pad[0x10c];
    struct Struct_0209a97c_3 unknown_10c_[13];
    int counts[16];
};
struct Holder0209a97c {
    struct Struct_0209a97c_2* base;
};

// USA: func_0209a97c
extern "C" ARM void func_0209a97c(struct Holder0209a97c* h, int slot, struct Pair0209a97c* src) {
    struct Struct_0209a97c_2* b = h->base;
    int count;
    if (b == NULL) return;
    count = b->counts[slot];
    if (count >= 0x14) return;
    b->counts[slot]++;
    {
        struct Pair0209a97c* dst = &h->base->unknown_10c_[slot].pairs[count];
        dst->a = src->a;
        dst->b = src->b;
    }
}
