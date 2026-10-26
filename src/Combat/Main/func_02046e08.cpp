#include <globaldefs.h>
#include "Memory/SafeAllocator.h"
#include "World/Object3D.h"

struct Struct_02046e08 {
    int unknown_0_;
    int unknown_4_;
    int unknown_8_;
    float unknown_c_;
    int unknown_10_;
    int unknown_14_;
    int unknown_18_;
    unsigned char unknown_1c_;
    unsigned char unknown_1d_;
    int unknown_20_;
    SafeAllocator allocator_;
    int unknown_38_;
    Object3D object_;
    int unknown_e8_;
    int unknown_ec_;
};

// USA: func_02046e08
extern "C" ARM void func_02046e08(Struct_02046e08* obj) {
    obj->unknown_0_ = 0;
    obj->unknown_4_ = 0;
    obj->unknown_20_ = 0;
    obj->unknown_8_ = 0;
    obj->unknown_c_ = 15.0f;
    obj->unknown_ec_ = -1;
    obj->unknown_1c_ = 1;
    obj->unknown_1d_ = 1;
    obj->object_.Initialize();
    obj->allocator_.ResetAllocatorPointer();
    obj->unknown_38_ = 0;
    obj->unknown_e8_ = 0;
    obj->unknown_10_ = 0;
    obj->unknown_14_ = 0;
    obj->unknown_18_ = 0;
}
