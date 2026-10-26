#include <globaldefs.h>
#include "World/Object3D.h"

struct Struct_02055558 {
    int field0;
    int field4;
    int field8;
    int fieldc;
    int field10;
    char sub14[0xc0 - 0x14];
    char unknown_c0_[4];
};

extern "C" void func_02054f80(void* obj);

// USA: func_02055558
extern "C" ARM int func_02055558(struct Struct_02055558* obj, int a2, int a3, int a4, int a5, int a6) {
    ((Object3D*)&obj->sub14)->Initialize();
    func_02054f80(&obj->unknown_c0_);
    obj->field0 = a2;
    obj->field4 = a3;
    obj->field8 = a6;
    obj->fieldc = a4;
    obj->field10 = a5;
    return 1;
}
