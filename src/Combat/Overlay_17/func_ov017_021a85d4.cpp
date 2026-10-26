#include <globaldefs.h>

struct Struct_ov017_021a85d4 {
    char pad[0x24];
    int unknown_24_;
    char pad2[0x10];
    unsigned short field0x38;
};

// USA: func_ov017_021a85d4
extern "C" ARM void func_ov017_021a85d4(struct Struct_ov017_021a85d4* obj, int val) {
    obj->unknown_24_ = val;
    if (val == 5) {
        obj->field0x38 = 0x3c;
    }
}
