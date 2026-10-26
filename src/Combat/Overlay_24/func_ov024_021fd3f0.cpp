#include <globaldefs.h>

struct Struct_02088514;
extern "C" int func_02088514(struct Struct_02088514* obj);

struct Struct_ov024_021fd3f0 {
    char unk[0x138];
    struct Struct_02088514* unknown_138_;
};

struct Struct_ov024_021fd3f0_2 {
    char unk[0x661];
    unsigned char unknown_661_;
    char unk2[0x668 - 0x661 - 1];
    struct Struct_ov024_021fd3f0* unknown_668_;
};

extern "C" void func_ov024_021fd160(void* obj, int mode);

// USA: func_ov024_021fd3f0
extern "C" ARM void func_ov024_021fd3f0(struct Struct_ov024_021fd3f0_2* obj) {
    if (func_02088514(obj->unknown_668_->unknown_138_)) {
        if (!obj->unknown_661_) {
            func_ov024_021fd160(obj, 2);
        }
    }
}
