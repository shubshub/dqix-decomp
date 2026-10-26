#include <globaldefs.h>

struct Struct_ov000_0217fbf4 {
    char pad0[0xc];
    short unknown_c_;
    char pad1[0x10 - 0xe];
    signed char field_0x10[8];
    signed char unknown_18_;
    char pad2[0x24 - 0x19];
    unsigned char flags;
    char pad3[0x4c - 0x25];
    int id;
#if defined(jpn)
    char pad4[0x488 - 0x50];
#else
    char pad4[0x448 - 0x50];
#endif
};

struct Struct_ov000_0217fbf4_2 {
    char pad0[0x6c];
    signed char order[4];
    char pad1[0x958 - 0x70];
    struct Struct_ov000_0217fbf4 unknown_958_[4];
};

// USA: func_ov000_0217fbf4
extern "C" ARM void func_ov000_0217fbf4(struct Struct_ov000_0217fbf4_2* obj, int id) {
    if (id < 0) {
        int i;
        for (i = 0; i < 4; i++) {
            struct Struct_ov000_0217fbf4* e = &obj->unknown_958_[obj->order[i]];
            if (e->id >= 0) {
                e->flags |= 1;
                if (e->unknown_c_ == 0) {
                    e->field_0x10[e->unknown_18_] = 100;
                    e->flags &= ~4;
                    e->flags &= ~1;
                }
            }
        }
        return;
    }
    int i;
    for (i = 0; i < 4; i++) {
        struct Struct_ov000_0217fbf4* e = &obj->unknown_958_[obj->order[i]];
        if (id == e->id) {
            e->flags |= 1;
            return;
        }
    }
}
