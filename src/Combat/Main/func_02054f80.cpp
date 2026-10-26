#include <globaldefs.h>
#include "NitroSDK/Memory/SignedAllocator.h"

struct Struct_02054f80 {
    int field0;
    int field4;
    SignedAllocatorList unknown_8_[3];
    SignedAllocatorList arr1[3];
    SignedAllocatorList arr2[3];
    SignedAllocatorList unknown_74_;
    SignedAllocatorList unknown_80_[3];
    SignedAllocatorList unknown_a4_;
    SignedAllocatorList unknown_b0_;
    SignedAllocatorList unknown_bc_;
    SignedAllocatorList unknown_c8_;
    SignedAllocatorList unknown_d4_;
    SignedAllocatorList unknown_e0_;
    SignedAllocatorList unknown_ec_;
    SignedAllocatorList unknown_f8_;
    SignedAllocatorList unknown_104_;
    SignedAllocatorList unknown_110_;
    SignedAllocatorList unknown_11c_;
};

// USA: func_02054f80
extern "C" ARM void func_02054f80(Struct_02054f80* obj) {
    obj->field0 = 0;
    obj->field4 = 0;

    for (int i = 0; i < 3; i++) {
        obj->unknown_8_[i].Initialize(4);
        obj->arr1[i].Initialize(4);
        obj->arr2[i].Initialize(4);
        obj->unknown_80_[i].Initialize(4);
    }

    obj->unknown_74_.Initialize(4);
    obj->unknown_a4_.Initialize(4);
    obj->unknown_b0_.Initialize(4);
    obj->unknown_bc_.Initialize(4);
    obj->unknown_c8_.Initialize(4);
    obj->unknown_d4_.Initialize(4);
    obj->unknown_e0_.Initialize(4);
    obj->unknown_ec_.Initialize(4);
    obj->unknown_f8_.Initialize(4);
    obj->unknown_104_.Initialize(4);
    obj->unknown_110_.Initialize(4);
    obj->unknown_11c_.Initialize(4);
}
