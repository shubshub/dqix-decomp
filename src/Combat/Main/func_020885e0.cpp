#include <globaldefs.h>

struct Struct_020885e0 {
    unsigned char pad0[0x14];
    unsigned int unknown_14_;
    unsigned int unknown_18_;
    unsigned char unknown_1c_[6];
    unsigned short kind : 2;
};

// USA: func_020885e0
extern "C" ARM int func_020885e0(struct Struct_020885e0* obj) {
    int f = obj->unknown_14_;
    if (f & 0x1) {
        return 0;
    }
    if (f & 0x1000000) {
        return 0;
    }
    if (f & 0x2) {
        if (obj->kind == 2) {
            return 0;
        }
    }
    return 1;
}
