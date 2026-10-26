#include <globaldefs.h>

struct Struct_020415c4 {
    char unk0[0x54];
    int field54;
    char unknown_58_[0x54];
    unsigned short flags;
    char unknown_ae_[0x2];
    int unknown_b0_;
};

// USA: func_020415c4
extern "C" ARM int func_020415c4(struct Struct_020415c4* obj) {
    if (obj->flags & 0x2) {
        return obj->unknown_b0_;
    }
    return obj->field54;
}
