#include <globaldefs.h>

struct Struct_ov024_021de124;
extern "C" int func_ov024_021de25c(struct Struct_ov024_021de124* obj);

struct Struct_ov024_021fd784 {
    char unk[0x661];
    unsigned char unknown_661_;
    char unk2[0x668 - 0x661 - 1];
    struct Struct_ov024_021de124* unknown_668_;
};

extern "C" void func_ov024_021fd160(void* obj, int mode);

// USA: func_ov024_021fd784
extern "C" ARM void func_ov024_021fd784(struct Struct_ov024_021fd784* obj) {
    if (func_ov024_021de25c(obj->unknown_668_)) {
        if (!obj->unknown_661_) {
            func_ov024_021fd160(obj, 7);
        }
    }
}
