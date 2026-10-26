#include <globaldefs.h>
#include "Memory/SafeAllocator.h"

struct Struct_020e5728 {
    void* data;
    int capacity;
    int size;
};

// USA: func_020e5850
extern "C" ARM void func_020e5850(struct Struct_020e5728* self, SafeAllocator* alloc, int count) {
    self->data = alloc->Allocate(count * 0x14);
    self->capacity = count;
    self->size = 0;
}
