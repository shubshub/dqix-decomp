#include <globaldefs.h>
#include "Memory/SafeAllocator.h"

extern "C" void* func_ov011_021842c8(void* obj);

struct Struct_ov011_021844a4 { char pad[0x9c]; void* f9c; unsigned int unknown_a0_; void* unknown_a4_; };

// USA: func_ov011_021844a4
extern "C" ARM int func_ov011_021844a4(struct Struct_ov011_021844a4* obj, void* p1, unsigned int size) {
    void* base = func_ov011_021842c8(obj);
    if (base == 0) return 1;
    void* r = ((SafeAllocator*)((char*)base + 4))->Allocate(size);
    obj->f9c = r;
    if (r == 0) return 1;
    obj->unknown_a4_ = p1;
    obj->unknown_a0_ = size;
    return 0;
}
