#include <globaldefs.h>
#include "NitroSDK/Memory/SignedAllocator.h"

struct Struct_020546c8;
extern "C" void* func_020550a8(struct Struct_020546c8* p);

struct Struct_020557a4;
extern "C" float func_020578e8(Struct_020557a4* a, Struct_020557a4* b);

struct Struct_020559cc {
    char pad0[0x24];
    unsigned char unknown_24_[3];
    unsigned char unknown_27_[3];
    unsigned char unknown_2a_[3];
};

struct Struct_020559cc_2 {
    char pad0[4];
    int field4;
    char pad8[0x28];
    void* unknown_30_;
    char unknown_34_[0x64 - 0x34];
    float unknown_64_[3];
    float unknown_70_[3];
    float unknown_7c_[3];
    unsigned short unknown_88_[3];
    unsigned short unknown_8e_[3];
    unsigned short unknown_94_[3];
};

// USA: func_020559cc
extern "C" ARM void func_020559cc(struct Struct_020559cc_2* obj) {
    struct Struct_020559cc* sub = (struct Struct_020559cc*)func_020550a8((struct Struct_020546c8*)obj->unknown_30_);

    for (int i = 0; i < 3; i++) {
        unsigned char count = sub->unknown_24_[i];
        if (count <= 1) continue;
        if (count <= obj->unknown_88_[i]) continue;
        SignedAllocatorHeader* elem =
            ((SignedAllocatorList*)((char*)obj->unknown_30_ + 0x8 + i * 12))->GetNthElement(obj->unknown_88_[i]);
        if (elem == NULL) continue;
        if ((unsigned int)(**(int**)elem) >= (unsigned int)obj->field4) continue;
        obj->unknown_88_[i]++;
        if (obj->unknown_88_[i] >= sub->unknown_24_[i]) {
            obj->unknown_64_[i] = 0;
            continue;
        }
        SignedAllocatorHeader* elem2 =
            ((SignedAllocatorList*)((char*)obj->unknown_30_ + 0x8 + i * 12))->GetNthElement(obj->unknown_88_[i]);
        if (elem2 == NULL) continue;
        obj->unknown_64_[i] = func_020578e8((Struct_020557a4*)elem, (Struct_020557a4*)elem2);
    }

    for (int i = 0; i < 3; i++) {
        unsigned char count = sub->unknown_27_[i];
        if (count <= 1) continue;
        if (count <= obj->unknown_8e_[i]) continue;
        SignedAllocatorHeader* elem =
            ((SignedAllocatorList*)((char*)obj->unknown_30_ + 0x2c + i * 12))->GetNthElement(obj->unknown_8e_[i]);
        if (elem == NULL) continue;
        if ((unsigned int)(**(int**)elem) >= (unsigned int)obj->field4) continue;
        obj->unknown_8e_[i]++;
        if (obj->unknown_8e_[i] >= sub->unknown_27_[i]) {
            obj->unknown_70_[i] = 0;
            continue;
        }
        SignedAllocatorHeader* elem2 =
            ((SignedAllocatorList*)((char*)obj->unknown_30_ + 0x2c + i * 12))->GetNthElement(obj->unknown_8e_[i]);
        if (elem2 == NULL) continue;
        obj->unknown_70_[i] = func_020578e8((Struct_020557a4*)elem, (Struct_020557a4*)elem2);
    }

    for (int i = 0; i < 3; i++) {
        unsigned char count = sub->unknown_2a_[i];
        if (count <= 1) continue;
        if (count <= obj->unknown_94_[i]) continue;
        SignedAllocatorHeader* elem =
            ((SignedAllocatorList*)((char*)obj->unknown_30_ + 0x50 + i * 12))->GetNthElement(obj->unknown_94_[i]);
        if (elem == NULL) continue;
        if ((unsigned int)(**(int**)elem) >= (unsigned int)obj->field4) continue;
        obj->unknown_94_[i]++;
        if (obj->unknown_94_[i] >= sub->unknown_2a_[i]) {
            obj->unknown_7c_[i] = 0;
            continue;
        }
        SignedAllocatorHeader* elem2 =
            ((SignedAllocatorList*)((char*)obj->unknown_30_ + 0x50 + i * 12))->GetNthElement(obj->unknown_94_[i]);
        if (elem2 == NULL) continue;
        obj->unknown_7c_[i] = func_020578e8((Struct_020557a4*)elem, (Struct_020557a4*)elem2);
    }
}
