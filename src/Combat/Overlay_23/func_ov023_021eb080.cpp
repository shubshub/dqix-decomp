#include <globaldefs.h>
#include "Memory/SafeAllocator.h"

struct Struct_ov023_021fd850 { unsigned int v[4]; };
extern struct Struct_ov023_021fd850 data_ov023_021fd850;

// USA: func_ov023_021eb080
extern "C" ARM void func_ov023_021eb080(void* obj, SafeAllocator* alloc) {
    if (alloc == NULL) return;
    struct Struct_ov023_021fd850 sizes = data_ov023_021fd850;
    *(void**)obj = alloc->Allocate(0x50);
    for (int i = 0; i < 4; i++) {
        SafeAllocator* a = &((SafeAllocator*)(*(void**)obj))[i];
        a->ResetAllocatorPointer();
        unsigned int sz = sizes.v[i];
        void* p = alloc->Allocate(sz);
        a->CreateTypeA(p, sz);
    }
    *(void**)((char*)obj + 0x424) = alloc->Allocate(0x54);
    *(void**)((char*)obj + 0x428) = alloc->Allocate(0xa0);
    *(void**)((char*)obj + 0x42c) = alloc->Allocate(0x8);
}
