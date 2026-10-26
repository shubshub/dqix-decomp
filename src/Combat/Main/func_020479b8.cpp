#include <globaldefs.h>

struct Struct_020479b8_4 {
    unsigned char unk0;
    unsigned char flag;
    unsigned char unk2[6];
};

struct Struct_020479b8 {
    int unk0;
    int unk4;
    int index;
};

struct Struct_020479b8_2 {
    int unk0;
    struct Struct_020479b8* list;
};

struct Struct_020479b8_3 {
    char unk0[8];
    struct Struct_020479b8_4* unknown_8_;
    struct Struct_020479b8_2* unknown_c_;
    char unk10[0x60];
    int unknown_70_;
    int unknown_74_;
    char unknown_78_[0xc];
    unsigned char unknown_84_0_ : 1;
    unsigned char unknown_84_1_ : 7;
};

// USA: func_020479b8
extern "C" ARM unsigned char func_020479b8(struct Struct_020479b8_3* base) {
    struct Struct_020479b8_2* a;
    struct Struct_020479b8* b;
    struct Struct_020479b8_4* e;
    if (base->unknown_84_0_ == 0) {
        return 0;
    }
    a = &base->unknown_c_[base->unknown_74_];
    b = &a->list[base->unknown_70_];
    e = &base->unknown_8_[b->index];
    return e->flag;
}
