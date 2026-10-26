#include <globaldefs.h>
#include "Memory/SafeAllocator.h"

struct Struct_020d6f0c {
    char pad[0xa28];
    SafeAllocator allocator;
};

// USA: func_020d6f0c
extern "C" ARM void func_020d6f0c(struct Struct_020d6f0c* self) {
    if (self->allocator.GetSignedAllocator() == NULL) return;
    self->allocator.Destroy();
    self->allocator.ResetAllocatorPointer();
}
