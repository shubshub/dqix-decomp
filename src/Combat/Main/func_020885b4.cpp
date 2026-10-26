#include <globaldefs.h>

struct Struct_020885b4 {
    unsigned char pad0[0x14];
    unsigned int unknown_14_;
    unsigned int unknown_18_;
    unsigned char unknown_1c_[6];
    unsigned short kind : 2;
};

// USA: func_020885b4
extern "C" ARM int func_020885b4(struct Struct_020885b4* obj) {
    if (obj->unknown_14_ & 0x2) {
        if (obj->kind == 1) {
            return 1;
        }
    }
    return 0;
}
