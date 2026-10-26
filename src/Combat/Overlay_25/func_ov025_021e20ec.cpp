#include <globaldefs.h>
#include "Memory/SafeAllocator.h"

struct Struct_ov025_021e20ec {
    void* data;
    int count;
};

// USA: func_ov025_021e20ec
extern "C" ARM void* func_ov025_021e20ec(struct Struct_ov025_021e20ec* obj, SafeAllocator* alloc) {
    obj->count = 0x51;
    return obj->data = alloc->Allocate(obj->count * 0xc);
}
