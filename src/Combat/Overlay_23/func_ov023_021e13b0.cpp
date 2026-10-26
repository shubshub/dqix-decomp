#include <globaldefs.h>
#include "Memory/SafeAllocator.h"

struct Struct_021e12cc;
extern "C" void func_ov023_021e12cc(struct Struct_021e12cc* s);

struct Struct_ov023_021e13b0 {
    char pad0[4];
    char* entries;
    short count;
    short capacity;
};

// USA: func_ov023_021e13b0
extern "C" ARM void func_ov023_021e13b0(Struct_ov023_021e13b0* obj, SafeAllocator* alloc, int capacity) {
    if (alloc == 0 || capacity == 0) return;
    obj->entries = (char*)alloc->Allocate(capacity * 0x10);
    obj->count = 0;
    obj->capacity = capacity;
    for (short i = 0; i < obj->capacity; i++) {
        func_ov023_021e12cc((struct Struct_021e12cc*)(obj->entries + i * 0x10));
    }
}
