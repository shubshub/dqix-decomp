#include <globaldefs.h>
#include "Memory/SafeAllocator.h"

struct Struct_0201a300_8 {
    char pad[0x24];
    unsigned char capacity;  // 0x24
    unsigned char count;     // 0x25
    char pad2[2];            // 0x26,0x27
    void* buffer;            // 0x28
};

// USA: func_0202834c
extern "C" ARM void func_0202834c(struct Struct_0201a300_8* obj, SafeAllocator* alloc, int count) {
    obj->buffer = alloc->Allocate(count * 4);
    obj->count = 0;
    obj->capacity = count;
}
