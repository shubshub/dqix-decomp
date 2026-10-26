#include <globaldefs.h>
#include "NitroSDK/Memory/SignedAllocator.h"

struct Struct_020546c8;
extern "C" void* func_020550c0(struct Struct_020546c8* p);

struct Struct_020557a4;
extern "C" float func_020578e8(Struct_020557a4* a, Struct_020557a4* b);

struct Struct_02055c30 {
    char pad0[4];
    int field4;
    char pad1[0x28];
    void* unknown_30_;
    char pad2[0x68];
    float unknown_9c_;
    unsigned short unknown_a0_;
};

// USA: func_02055c30
extern "C" ARM void func_02055c30(struct Struct_02055c30* obj) {
    void* var0 = func_020550c0((struct Struct_020546c8*)obj->unknown_30_);
    if (*(unsigned char*)((char*)var0 + 4) <= 1) return;
    if (*(unsigned char*)((char*)var0 + 4) <= obj->unknown_a0_) return;

    SignedAllocatorHeader* elem = ((SignedAllocatorList*)((char*)obj->unknown_30_ + 0x74))->GetNthElement(obj->unknown_a0_);
    if (elem == NULL) return;
    if ((unsigned int)(**(int**)elem) >= (unsigned int)obj->field4) return;

    obj->unknown_a0_ = obj->unknown_a0_ + 1;
    if (obj->unknown_a0_ >= *(unsigned char*)((char*)var0 + 4)) {
        obj->unknown_9c_ = 0;
        return;
    }
    SignedAllocatorHeader* elem2 = ((SignedAllocatorList*)((char*)obj->unknown_30_ + 0x74))->GetNthElement(obj->unknown_a0_);
    if (elem2 == NULL) return;
    obj->unknown_9c_ = func_020578e8((Struct_020557a4*)elem, (Struct_020557a4*)elem2);
}
