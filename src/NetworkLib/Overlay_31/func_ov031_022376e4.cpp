#include <globaldefs.h>

struct Struct_ov031_022376e4 { unsigned char pad[0x1370]; int unknown_1370_; };
extern Struct_ov031_022376e4* data_ov031_02290d0c;

// USA: func_ov031_022376e4
extern "C" ARM void func_ov031_022376e4(int val) {
    data_ov031_02290d0c->unknown_1370_ = val;
}
