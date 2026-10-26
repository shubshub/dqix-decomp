#include <globaldefs.h>

struct Struct_0209ab7c_2 { unsigned short a; unsigned short b; };
struct Struct_0209ab7c_5 {
    unsigned char pad0[0xc];
    struct Struct_0209ab7c_2 pairs[17];
};
struct Struct_0209ab7c {
    unsigned char unknown_0_[0x100];
    struct Struct_0209ab7c_5 slots[13];
    unsigned char unknown_510_[0xc];
    int counts[16];
};
struct Struct_0209ab7c_3 {
    struct Struct_0209ab7c* base;
};
struct Struct_0209ab7c_4 {
#if defined(jpn)
    unsigned char pad[0x8b8];
#else
    unsigned char pad[0x950];
#endif
    int slot;
};

extern "C" int func_02053c6c(unsigned char* obj);

// USA: func_0209ab7c
extern "C" ARM int func_0209ab7c(struct Struct_0209ab7c_3* h, unsigned char* path, unsigned char* out,
                                 int threshold) {
    if (&h->base->slots[0].pairs[0] == NULL) return 0;
    if (&h->base->counts[0] == NULL) return 0;
    struct Struct_0209ab7c_4* f = (struct Struct_0209ab7c_4*)func_02053c6c(path);
    if (f == 0) return 0;
    int slot = f->slot;
    int idx;
    unsigned short a;
    int count = 0;
    for (idx = 0; idx < h->base->counts[slot]; idx++) {
        int var5 = *(unsigned short*)((unsigned char*)f + f->slot * 2 + 0x100 + 0x6c);
        int b = h->base->slots[slot].pairs[idx].b;
        a = h->base->slots[slot].pairs[idx].a;
        if (var5 >= b) {
            out[count] = (unsigned char)a;
            count++;
        }
    }
    return count;
}
