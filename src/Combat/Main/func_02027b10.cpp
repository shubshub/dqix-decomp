#include <globaldefs.h>

#if defined(jpn)
enum { Enum_02027b10_2712 = 0x9cc };
#else
enum { Enum_02027b10_2712 = 0xa98 };
#endif
#include "Memory/SafeAllocator.h"
#include "Resource/GameResources.h"

struct Struct_02027b10 {
    char pad0[Enum_02027b10_2712];
    unsigned char unknown_a98_;
    unsigned char unknown_a99_;
    char pad1[2];
    void* unknown_a9c_;
};

// USA: func_02027b10
extern "C" ARM void func_02027b10(struct Struct_02027b10* obj, unsigned int count) {
    int base = (int)GetGameResources();
    SafeAllocator* alloc;
    if (obj->unknown_a9c_ != 0) {
        alloc = (SafeAllocator*)(base + 0x128);
        alloc->Free(obj->unknown_a9c_);
    } else {
        alloc = (SafeAllocator*)(base + 0x128);
    }
    obj->unknown_a9c_ = alloc->Allocate(count * 0xc);
    obj->unknown_a98_ = count;
    obj->unknown_a99_ = 0;
}
