#include <globaldefs.h>
#include "World/Object3D.h"

struct Struct_0203d028_20 {
    char unknown_0_[0xc4];
    char field_c4;
    char unknown_c5_[0xb];
    int field_d0;
};

// USA: func_02041598
extern "C" ARM int func_02041598(struct Struct_0203d028_20* obj, int value, int) {
    obj->field_c4 = value;
    return ((Object3D*)obj)->SetAnimationByIndex((unsigned char)value, obj->field_d0);
}
