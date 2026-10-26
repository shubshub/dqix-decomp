#include <globaldefs.h>

struct Struct_ov014_02184f10 {
    char pad0[0x48];
    int unknown_48_;
    int unknown_4c_;
    int unknown_50_;
    int unknown_54_;
    char pad1[0x7c - 0x58];
    unsigned char f7c;
    char pad2[0x81 - 0x7d];
    unsigned char unknown_81_;
};

extern "C" void func_ov014_02184f78(struct Struct_ov014_02184f10* obj, int a, int b, int flag);

// USA: func_ov014_02184f10
extern "C" ARM void func_ov014_02184f10(struct Struct_ov014_02184f10* o, int a, int b) {
    if (!o->f7c) {
        return;
    }
    if (o->unknown_4c_ != o->unknown_48_) {
        o->unknown_4c_ = o->unknown_48_;
        o->unknown_54_ = o->unknown_50_;
        o->unknown_81_ |= 0x20;
    }
    if (a == 0 || b == 0) {
        o->unknown_48_ = a;
        return;
    }
    if (o->unknown_48_ == a || o->unknown_50_ == b) {
        return;
    }
    func_ov014_02184f78(o, a, b, 1);
}
