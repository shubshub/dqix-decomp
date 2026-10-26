#include <globaldefs.h>

struct Struct_ov024_021f6ae8_2 {
    char unk[0xa];
    unsigned short unknown_a_0_ : 12;
    unsigned short unknown_b_4_ : 1;
    unsigned short unknown_b_5_ : 3;
};

struct Struct_ov024_021f6ae8 {
    char unk0[8];
    struct Struct_ov024_021f6ae8_2* sub;
    char unknown_c_[0x10];
    float f1c;
    float f20;
};

// USA: func_ov024_021f6ae8
extern "C" ARM int func_ov024_021f6ae8(struct Struct_ov024_021f6ae8* obj) {
    struct Struct_ov024_021f6ae8_2* sub = obj->sub;
    if (sub != NULL && sub->unknown_b_4_) {
        obj->f1c = 2.0f;
        obj->f20 = 1.0f;
    } else {
        obj->f1c = 0.0f;
        obj->f20 = 0.0f;
    }
    return 1;
}
