#include <globaldefs.h>
#include "Memory/SafeAllocator.h"

struct Struct_ov003_0217f280 { unsigned int v[1]; };
extern Struct_ov003_0217f280 data_ov003_0217f280[];

// USA: func_ov003_021536e0
extern "C" ARM void func_ov003_021536e0(void* obj, SafeAllocator* alloc) {
    *(void**)obj = alloc->Allocate(0x14);
    struct Struct_ov003_0217f280 sizes = data_ov003_0217f280[1];
    for (unsigned char i = 0; i < 1; i++) {
        ((SafeAllocator*)((char*)*(void**)obj + i * 0x14))->ResetAllocatorPointer();
        unsigned int sz = sizes.v[i];
        void* p = alloc->Allocate(sz);
        ((SafeAllocator*)((char*)*(void**)obj + i * 0x14))->CreateTypeA(p, sz);
    }
}
