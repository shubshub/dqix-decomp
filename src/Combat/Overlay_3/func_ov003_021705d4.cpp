#include <globaldefs.h>

struct Struct_ov003_021705d4 {
    char pad0[1];
    signed char field1;
    char pad2[4];
    signed char field6;
    char unknown_7_[0x19];
    unsigned short field20;
};

// USA: func_ov003_021705d4
#pragma optimize_for_size off
extern "C" ARM void func_ov003_021705d4(struct Struct_ov003_021705d4* obj, unsigned short* out1, unsigned short* out2) {
    if (obj->field1 == 5) {
        if ((obj->field20 & 4) == 0 || (obj->field6 >= 0 && obj->field6 <= 3)) {
            *out1 = 4;
            *out2 = (obj->field6 << 4) + 0x2b;
            return;
        }
        *out1 = 0;
        *out2 = 0;
        return;
    }
    *out1 = 0;
    *out2 = 0;
}
