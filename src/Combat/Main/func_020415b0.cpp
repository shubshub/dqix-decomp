#include <globaldefs.h>
#include "World/Object3D.h"

struct Struct_0203d028_21 {
    char unknown_0_[0xcc];
    int field_cc;
    int field_d0;
};

// USA: func_020415b0
extern "C" ARM int func_020415b0(Struct_0203d028_21* obj, int value, int) {
    obj->field_cc = value;
    return ((Object3D*)obj)->SetAnimationByName((char const*)value, obj->field_d0);
}
