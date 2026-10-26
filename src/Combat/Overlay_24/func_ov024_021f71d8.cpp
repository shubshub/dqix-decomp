#include <globaldefs.h>

struct Struct_021f71d8 {
    char unk0[0xc];
    unsigned short unknown_c_;
    char unknown_e_[0x14 - 0xe];
    float unknown_14_;
    float unknown_18_;
    float unknown_1c_;
    float unknown_20_;
};

// USA: func_ov024_021f71d8
extern "C" ARM int func_ov024_021f71d8(struct Struct_021f71d8* obj) {
    obj->unknown_1c_ = (4.0f * obj->unknown_14_) / (float)(obj->unknown_c_ + 1);
    obj->unknown_20_ = (4.0f * obj->unknown_18_) / (float)(obj->unknown_c_ + 1);
    return 1;
}
