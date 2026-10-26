#include <globaldefs.h>
#include "std_library_functions.h"

struct Struct_ov000_02157d14 {
    char pad0[0x1c];
    short unknown_1c_;
    char pad1[0x12];
    int unknown_30_;
};

// USA: func_ov000_02157d14
extern "C" ARM void func_ov000_02157d14(struct Struct_ov000_02157d14* obj) {
    memset(obj, 0, 0x30);
    obj->unknown_1c_ = -1;
    obj->unknown_30_ = 0;
}
