#include <globaldefs.h>

struct Struct_0209ac28_2 { unsigned short a; unsigned short b; };
struct Struct_0209ac28_5 {
    unsigned char pad0[0xc];
    struct Struct_0209ac28_2 pairs[17];
};
struct Struct_0209ac28 {
    unsigned char unknown_0_[0x100];
    struct Struct_0209ac28_5 slots[13];
    unsigned char unknown_510_[0xc];
    int counts[16];
};
struct Struct_0209ac28_3 {
    struct Struct_0209ac28* base;
};
struct Struct_0209ac28_4 {
#if defined(jpn)
    unsigned char pad[0x8b8];
#else
    unsigned char pad[0x950];
#endif
    int slot;
};

extern "C" int func_02053c6c(unsigned char* obj);

// USA: func_0209ac28
extern "C" ARM int func_0209ac28(struct Struct_0209ac28_3* h, unsigned char* path, int key) {
    if (&h->base->slots[0].pairs[0] == NULL) return 0;
    if (&h->base->counts[0] == NULL) return 0;
    struct Struct_0209ac28_4* f = (struct Struct_0209ac28_4*)func_02053c6c(path);
    if (f == 0) return 0;
    int slot = f->slot & 0xff;
    int var2 = *(unsigned short*)((unsigned char*)f + slot * 2 + 0x100 + 0x6c) & 0xff;
    int idx;
    for (idx = 0; idx < h->base->counts[slot]; idx++) {
        if (h->base->slots[slot].pairs[idx].a == key) {
            return h->base->slots[slot].pairs[idx].b <= var2;
        }
    }
    return 0;
}
