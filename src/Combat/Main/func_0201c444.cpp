#include <globaldefs.h>
#include "Memory/SafeAllocator.h"

struct Struct_0201c444 {
    char pad0[0xc];       // 0x0..0xb
    void* ptr;            // 0xc
    char pad1[0x4];       // 0x10..0x13
    int count;            // 0x14
    char pad2[0x8];       // 0x18..0x1f
    SafeAllocator* alloc; // 0x20
};

// USA: func_0201c444
extern "C" ARM void func_0201c444(struct Struct_0201c444* obj, int count) {
    obj->ptr = obj->alloc->Allocate(count * 0x2c);
    if (obj->ptr != NULL) {
        obj->count = count;
    }
}
