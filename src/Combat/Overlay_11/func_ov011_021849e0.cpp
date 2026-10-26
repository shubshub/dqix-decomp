#include <globaldefs.h>

struct Struct_ov004_02158dcc { char pad[0x1b0]; unsigned short unknown_1b0_; char pad2[0x1c8-0x1b2]; int unknown_1c8_; };

// USA: func_ov011_021849e0
extern "C" ARM void func_ov011_021849e0(Struct_ov004_02158dcc* obj, unsigned short val) {
    if (obj->unknown_1b0_ != val) {
        obj->unknown_1c8_ = 1;
    }
    obj->unknown_1b0_ = val;
}
