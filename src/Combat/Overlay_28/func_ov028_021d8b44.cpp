#include <globaldefs.h>
#include "Memory/SafeAllocator.h"

struct Struct_ov028_021d8b44 {
    char pad[0x40];
    void* field40;
    SafeAllocator allocator;
};

// USA: func_ov028_021d8b44
extern "C" ARM void func_ov028_021d8b44(Struct_ov028_021d8b44* self, SafeAllocator* alloc) {
    if (alloc == 0) {
        return;
    }
    void* p1 = alloc->AllocateReversed(0xa000);
    self->field40 = (char*)p1 + 0x1000;
    self->allocator.ResetAllocatorPointer();
    void* p2 = alloc->AllocateReversed(0x5000);
    self->allocator.CreateTypeA(p2, 0x5000);
}
