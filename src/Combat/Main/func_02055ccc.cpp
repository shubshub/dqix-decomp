#include <globaldefs.h>
#include "NitroSDK/Memory/SignedAllocator.h"

struct Struct_020546c8;
extern "C" void* func_020550d8(struct Struct_020546c8* p);

struct Struct_02055ccc {
    int x;
    float y;
    float z;
    float w;
};

struct Struct_020557a4;
extern "C" float func_020578e8(Struct_020557a4* a, Struct_020557a4* b);

struct Struct_02055ccc_2 {
    Struct_02055ccc* p;
};

struct Struct_02055ccc_3 {
    char pad0[0x10];
    unsigned char f10[3];
    unsigned char unknown_13_;
};

struct Struct_02055ccc_4 {
    char pad0[4];
    int field4;
    char pad1[0x28];
    void* unknown_30_;
    char pad2[0x70];
    float unknown_a4_[3];
    float fieldB0;
    float fieldB4;
    float fieldB8;
    unsigned short fieldBC[3];
    unsigned short unknown_c2_;
};

// USA: func_02055ccc
extern "C" ARM void func_02055ccc(struct Struct_02055ccc_4* self) {
    Struct_02055ccc_3* sub = (Struct_02055ccc_3*)func_020550d8((struct Struct_020546c8*)self->unknown_30_);

    for (int i = 0; i < 3; i++) {
        if (sub->f10[i] <= 1)
            continue;
        if (sub->f10[i] <= self->fieldBC[i])
            continue;
        Struct_02055ccc_2* elem = (Struct_02055ccc_2*)((SignedAllocatorList*)((char*)self->unknown_30_ + 0x80 + i * 12))->GetNthElement(self->fieldBC[i]);
        if (elem == 0)
            continue;
        if ((unsigned int)elem->p->x >= (unsigned int)self->field4)
            continue;
        *(unsigned short*)((char*)self + 0xbc + i * 2) = *(unsigned short*)((char*)self + 0xbc + i * 2) + 1;
        if (self->fieldBC[i] >= sub->f10[i]) {
            self->unknown_a4_[i] = 0;
            continue;
        }
        Struct_02055ccc_2* elem2 = (Struct_02055ccc_2*)((SignedAllocatorList*)((char*)self->unknown_30_ + 0x80 + i * 12))->GetNthElement(self->fieldBC[i]);
        if (elem2 == 0)
            continue;
        self->unknown_a4_[i] = func_020578e8((Struct_020557a4*)elem, (Struct_020557a4*)elem2);
    }

    if (sub->unknown_13_ <= 1)
        return;
    if (sub->unknown_13_ <= self->unknown_c2_)
        return;
    Struct_02055ccc_2* elem = (Struct_02055ccc_2*)((SignedAllocatorList*)((char*)self->unknown_30_ + 0xa4))->GetNthElement(self->unknown_c2_);
    if (elem == 0)
        return;
    if ((unsigned int)elem->p->x >= (unsigned int)self->field4)
        return;
    self->unknown_c2_ = self->unknown_c2_ + 1;
    if (self->unknown_c2_ >= sub->unknown_13_) {
        self->fieldB0 = self->fieldB4 = self->fieldB8 = 0;
        return;
    }
    Struct_02055ccc_2* elem2 = (Struct_02055ccc_2*)((SignedAllocatorList*)((char*)self->unknown_30_ + 0xa4))->GetNthElement(self->unknown_c2_);
    if (elem2 == 0)
        return;
    self->fieldB0 = (elem2->p->y - elem->p->y) / (float)(elem2->p->x - elem->p->x);
    self->fieldB4 = (elem2->p->z - elem->p->z) / (float)(elem2->p->x - elem->p->x);
    self->fieldB8 = (elem2->p->w - elem->p->w) / (float)(elem2->p->x - elem->p->x);
}
