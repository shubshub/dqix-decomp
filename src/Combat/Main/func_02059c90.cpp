#include <globaldefs.h>

struct Struct_02059c90_2 {
    char unk0[0x28];
    unsigned short field28;
    unsigned short field2a;
};

struct Struct_02059c90 {
    char unk0[0x54];
    struct Struct_02059c90_2* field54;
};

struct Struct_020577cc_2 {
    char unk0[0x84];
    struct Struct_02059c90* unknown_84_;
};

// USA: func_02059c90
extern "C" ARM void func_02059c90(struct Struct_020577cc_2* obj, unsigned short* out0, unsigned short* out1) {
    *out0 = obj->unknown_84_->field54->field28;
    *out1 = obj->unknown_84_->field54->field2a;
}
