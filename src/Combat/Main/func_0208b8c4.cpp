#include <globaldefs.h>
#include "Memory/SafeAllocator.h"

struct Struct0205a198;
extern "C" void Sprite_Init(struct Struct0205a198*);

struct Struct_020e8cd0 {
    unsigned int v[5];
};
extern Struct_020e8cd0 data_020e8cd0;

struct Struct_0208b8c4 {
    SafeAllocator* unknown_0_;
    char pad1[0xb0];
    void* buf2;
    char pad2[0x27];
    unsigned char flag;
};

// USA: func_0208b8c4
extern "C" ARM void func_0208b8c4(struct Struct_0208b8c4* obj, SafeAllocator* allocator) {
    int i;

    obj->unknown_0_ = (SafeAllocator*)allocator->Allocate(0x64);
    obj->buf2 = allocator->Allocate(0x78);

    for (i = 0; i < 3; i++) {
        Sprite_Init((struct Struct0205a198*)((char*)obj->buf2 + i * 0x28));
    }

    unsigned char flag = obj->flag;
    unsigned int last = 0x7000;
    if (flag != 0) {
        last = 0;
    }
    Struct_020e8cd0 local;
    local = data_020e8cd0;
    local.v[4] = last;

    for (i = 0; i < 5; i++) {
        obj->unknown_0_[i].ResetAllocatorPointer();
        void* p = allocator->Allocate(local.v[i]);
        obj->unknown_0_[i].CreateTypeA(p, local.v[i]);
    }
}
