#include <globaldefs.h>

struct Struct_0209aa54_2 { unsigned short a; unsigned short b; };
struct Struct_0209aa54_5 {
    unsigned char pad0[0xc];
    struct Struct_0209aa54_2 pairs[17];
};
struct Struct_0209aa54 {
    unsigned char unknown_0_[0x100];
    struct Struct_0209aa54_5 slots[13];
    unsigned char unknown_510_[0xc];
    int counts[16];
};
struct Struct_0209aa54_3 {
    struct Struct_0209aa54* base;
};
struct Struct_0209aa54_4 {
#if defined(jpn)
    unsigned char pad[0x8b8];
#else
    unsigned char pad[0x950];
#endif
    int slot;
};

extern "C" int func_02053c6c(unsigned char* obj);
extern "C" void PartyMember_LearnSpell(unsigned char* obj, int index);

// USA: func_0209aa54
extern "C" ARM int func_0209aa54(struct Struct_0209aa54_3* h, unsigned char* path, unsigned char* out,
                                int threshold) {
    if (&h->base->slots[0].pairs[0] == NULL) return 0;
    if (&h->base->counts[0] == NULL) return 0;
    struct Struct_0209aa54_4* f = (struct Struct_0209aa54_4*)func_02053c6c(path);
    if (f == 0) return 0;
    int slot = f->slot;
    int idx;
    unsigned short a;
    int count = 0;
    for (idx = 0; idx < h->base->counts[slot]; idx++) {
        int b = h->base->slots[slot].pairs[idx].b;
        int var6 = *(unsigned short*)((unsigned char*)f + f->slot * 2 + 0x100 + 0x6c);
        a = h->base->slots[slot].pairs[idx].a;
        if (var6 >= b && b > threshold) {
            PartyMember_LearnSpell((unsigned char*)f, a);
            out[count] = (unsigned char)a;
            count++;
        }
    }
    return count;
}
