#include <globaldefs.h>
#include "Memory/SafeAllocator.h"

struct Container0215e750 {
    void* base;
    unsigned short count;
    unsigned short zero;
};

// USA: func_ov003_0215e750
extern "C" ARM void func_ov003_0215e750(struct Container0215e750* obj, SafeAllocator* alloc, int count) {
    if (alloc == NULL) return;
    if (count < 0) return;
    obj->base = alloc->Allocate(count * 0x14);
    obj->count = (unsigned short)count;
    obj->zero = 0;
}
