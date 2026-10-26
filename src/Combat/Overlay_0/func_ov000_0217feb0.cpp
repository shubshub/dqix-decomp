#include <globaldefs.h>

struct Struct_ov000_0217feb0_2 {
    char pad0[0x4c];
    int id;
#if defined(jpn)
    char pad1[0xc7 - 0x50];
#else
    char pad1[0x87 - 0x50];
#endif
    unsigned char unknown_87_;
    char pad2[0x448 - 0x88];
};

struct Struct_ov000_0217feb0 {
    char pad0[0x6c];
    signed char slots[4];
    char pad1[0x958 - 0x70];
    struct Struct_ov000_0217feb0_2 entries[1];
};

static inline struct Struct_ov000_0217feb0_2* inline_ov000_0217feb0(struct Struct_ov000_0217feb0* obj, int i) {
    return &obj->entries[obj->slots[i]];
}

// USA: func_ov000_0217feb0
extern "C" ARM void func_ov000_0217feb0(struct Struct_ov000_0217feb0* obj, unsigned char value, int id) {
    if (id < 0) {
        for (int i = 0; i < 4; i++) {
            struct Struct_ov000_0217feb0_2* e = inline_ov000_0217feb0(obj, i);
            e->unknown_87_ = value;
        }
    } else {
        for (int i = 0; i < 4; i++) {
            struct Struct_ov000_0217feb0_2* e = inline_ov000_0217feb0(obj, i);
            if (id == e->id) {
                e->unknown_87_ = value;
                return;
            }
        }
    }
}
