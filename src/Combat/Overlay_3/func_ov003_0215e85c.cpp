#include <globaldefs.h>
#include "Memory/SafeAllocator.h"

struct Array0215e85c {
    char pad[8];
    void* data;
    unsigned short count;
    unsigned short cursor;
};

// USA: func_ov003_0215e85c
extern "C" ARM void func_ov003_0215e85c(struct Array0215e85c* self, class SafeAllocator* allocator, int count) {
    if (allocator == NULL) {
        return;
    }
    if (count < 0) {
        return;
    }
    self->data = allocator->Allocate(count * 8);
    self->count = count;
    self->cursor = 0;
}
