#include <globaldefs.h>

struct Struct_ov024_021da670_7;
extern "C" int func_ov024_021da9b0(struct Struct_ov024_021da670_7* obj);

struct Struct_ov024_021fd428 {
    char unk[0x661];
    unsigned char unknown_661_;
    char unk2[0x668 - 0x661 - 1];
    struct Struct_ov024_021da670_7* unknown_668_;
};

extern "C" void func_ov024_021fd160(void* obj, int mode);

// USA: func_ov024_021fd428
extern "C" ARM void func_ov024_021fd428(struct Struct_ov024_021fd428* obj) {
    if (func_ov024_021da9b0(obj->unknown_668_)) {
        if (!obj->unknown_661_) {
            func_ov024_021fd160(obj, 3);
        }
    }
}
