#include <globaldefs.h>
#include "Memory/SafeAllocator.h"

struct Foo0204af38 {
    char _pad0[0x10];
    void* buffer;        // 0x10
    char _pad1[0xa];     // 0x14
    unsigned char count; // 0x1e
};

// Main, originally AllocateArray0204af38 (USA 0x0204af38, EUR 0x0204af48, JPN 0x0204bd58)
ARM void Background_AllocateScreens(struct Foo0204af38* obj, int count, SafeAllocator* alloc) {
    if (alloc == NULL) return;
    obj->buffer = alloc->Allocate(count * 0x10);
    obj->count = count;
}
