#include <globaldefs.h>
#include "Memory/SafeAllocator.h"

struct Struct_02089ea0 {
    void* buffer;
    short field4;
    short capacity;
};

// USA: func_02089ea0
extern "C" ARM void func_02089ea0(struct Struct_02089ea0* out, SafeAllocator* alloc, int count) {
    if (alloc == NULL) return;
    if (count < 0) return;
    out->buffer = alloc->Allocate(count << 6);
    out->field4 = 0;
    out->capacity = count;
}
