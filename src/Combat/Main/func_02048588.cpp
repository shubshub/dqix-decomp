#include <globaldefs.h>
#include "World/Object3D.h"

extern "C" void _ZN8Object3D14ShallowCloneToEPS_(void* self);

struct Struct_02048588 {
    unsigned char pad[0x10];
    unsigned int unknown_10_0_ : 27;
    unsigned int unknown_13_3_ : 1;
    unsigned int unknown_13_4_ : 4;
};

// USA: func_02048588
extern "C" ARM void func_02048588(unsigned char* self, unsigned char* dst) {
    _ZN8Object3D14ShallowCloneToEPS_(self);
    *(int*)(dst + 0x148) = *(int*)(self + 0xb0);
    *(int*)(dst + 0x144) = *(int*)(self + 0xac);
    int* target = *(int**)(dst + 0x13c);
    if (target != 0) {
        *target = *(int*)(self + 0xb4);
    }
    *(int*)(dst + 0x134) = *(int*)(self + 0xb0) + 0x2c;
    if (((Object3D*)self)->GetFlags() & 0x20000000) {
        ((Object3D*)dst)->EnableFlag(0x20000000);
    }
    Struct_02048588* p = *(Struct_02048588**)(self + 0xb0);
    unsigned int bit = p->unknown_13_3_;
    if (bit) {
        *(dst + 0xc2) &= ~0x10;
    } else {
        *(dst + 0xc2) |= 0x10;
    }
    void* q = *(void**)(self + 0xac);
    *(short*)(dst + 0x18e) = *(short*)((char*)q + 0x12);
}
