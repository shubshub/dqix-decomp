#include <globaldefs.h>
#include "Memory/SafeAllocator.h"

struct Struct_02047b40_5 {
    int count;      // 0x0
    void* buffer;   // 0x4
};

// USA: func_02048090
extern "C" ARM void func_02048090(struct Struct_02047b40_5* obj, int count, SafeAllocator* alloc) {
    obj->count = count;
    obj->buffer = alloc->Allocate(obj->count * 0x1e);
}
