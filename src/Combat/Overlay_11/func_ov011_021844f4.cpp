#include <globaldefs.h>
#include "Memory/SafeAllocator.h"

extern "C" void* func_ov011_021842c8(void* obj);

struct Struct_ov011_021844f4 {
    char pad[0xb0];
    void* unknown_b0_;
    unsigned int field_b4;
};

// USA: func_ov011_021844f4
extern "C" ARM int func_ov011_021844f4(Struct_ov011_021844f4* obj, int unused, unsigned int size) {
    void* target = func_ov011_021842c8(obj);
    if (!target) return 0;
    void* mem = ((SafeAllocator*)((char*)target + 4))->Allocate(size);
    obj->unknown_b0_ = mem;
    if (!mem) return 0;
    obj->field_b4 = size;
    return 1;
}
