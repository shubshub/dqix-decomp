#include <globaldefs.h>
#include "Memory/SafeAllocator.h"

struct Struct_ov023_021fbe4c {
    char pad[0x20];
    SafeAllocator allocator;
};

// USA: func_ov023_021fbe4c
extern "C" ARM void func_ov023_021fbe4c(struct Struct_ov023_021fbe4c* self) {
    if (self->allocator.GetSignedAllocator() == NULL) return;
    self->allocator.Destroy();
}
