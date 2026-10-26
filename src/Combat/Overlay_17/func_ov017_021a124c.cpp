#include <globaldefs.h>
#include "Memory/SafeAllocator.h"

struct ByteHeader0204693c;
extern "C" void func_0204693c(struct ByteHeader0204693c* p);

// USA: func_ov017_021a124c
extern "C" ARM void func_ov017_021a124c(unsigned char* self) {
    func_0204693c((struct ByteHeader0204693c*)self);
    self[0] = 2;
    ((SafeAllocator*)(self + 8))->ResetAllocatorPointer();
    *(int*)(self + 0x1c) = 0;
    self[0x20] = 2;
    self[0x21] = 0;
    self[0x22] = 0;
}
