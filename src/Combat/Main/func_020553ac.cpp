#include <globaldefs.h>
#include "World/Object3D.h"

struct Struct_020553ac {
    int field0;
    int field4;
    int field8;
    int fieldc;
    int field10;
    char sub14[0xc0 - 0x14];
    char unknown_c0_[0x1e8 - 0xc0];
    int unknown_1e8_;
    int unknown_1ec_;
};

extern "C" void func_02054f80(void* obj);

// USA: func_020553ac
extern "C" ARM void func_020553ac(struct Struct_020553ac* obj) {
    obj->field0 = -1;
    obj->unknown_1ec_ = 0;
    obj->field4 = 0;
    obj->field8 = 0;
    obj->fieldc = 0;
    obj->field10 = 0;
    obj->unknown_1e8_ = 0;
    ((Object3D*)&obj->sub14)->Initialize();
    func_02054f80(&obj->unknown_c0_);
}
