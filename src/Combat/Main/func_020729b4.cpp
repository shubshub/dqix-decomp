#include <globaldefs.h>
#include "Memory/SafeAllocator.h"

struct Struct_02000c9c_24 { short f0; int f4; };
struct Struct_020729b4 {
    void* ptr;      // 0x0
    short unknown_4_;  // 0x4
    short unknown_6_;       // 0x6
};

// USA: func_020729b4
extern "C" ARM void func_020729b4(Struct_020729b4* self, SafeAllocator* alloc, unsigned int count) {
    if (self->ptr != 0) return;
    self->unknown_6_ = 0;
    self->unknown_4_ = (short)count;
    self->ptr = alloc->Allocate(count * 8);
    for (unsigned short i = 0; i < count; i++) {
        ((short*)self->ptr)[i * 4] = -1;
        *(int*)((char*)self->ptr + i * 8 + 4) = 0;
    }
}
