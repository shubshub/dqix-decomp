#include <globaldefs.h>
#include "Memory/SafeAllocator.h"

struct Struct_0207ed1c {
    void* entries;   // 0x0
    short idx;       // 0x4
    short count;     // 0x6
};

// USA: func_0207efdc
extern "C" ARM void func_0207efdc(struct Struct_0207ed1c* obj, SafeAllocator* alloc, int count) {
    if (alloc == NULL) return;
    if (count < 0) return;
    obj->idx = 0;
    obj->count = count;
    obj->entries = alloc->Allocate(count * 0x18);
}
