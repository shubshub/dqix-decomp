#include <globaldefs.h>
#include "World/Object3D.h"

struct Struct_02048850_2 {
    char pad0[0xc];
    short fieldC;
    short unknown_e_;
};

struct Struct_02048850 {
    char pad0[0x144];
    struct Struct_02048850_2* unknown_144_;
};

// USA: func_02048850
extern "C" ARM void func_02048850(struct Struct_02048850* obj, struct Struct_02048850_2* p) {
    obj->unknown_144_ = p;
    ((Object3D*)((struct Struct_020484f8_3*)(obj)))->SetRadius((int)(p->fieldC << 2));
    ((Object3D*)((struct Struct_020484f8_4*)(obj)))->SetHeight((int)(obj->unknown_144_->unknown_e_));
}
