#include <globaldefs.h>

#include "Combat/DistanceSort.h"

extern "C" void _ZN8Object3D4DrawEb(void* obj, int flag);

struct Struct_0205a148 {
    unsigned char unknown_0_[0xac];
    int field_ac;
    short unknown_b0_;
    unsigned char unknown_b2_[0x1a];
    unsigned char field_cc;
};

// USA: func_0205a148
extern "C" ARM void func_0205a148(struct Struct_0205a148* obj) {
    if (obj->unknown_b0_ > 0) return;
    if (obj->field_ac == 0) {
        _ZN8Object3D4DrawEb(obj, ((unsigned int)obj->field_cc << 29) >> 31);
        return;
    }
    func_0205578c((int*)obj);
}
