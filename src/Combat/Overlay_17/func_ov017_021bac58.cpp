#include <globaldefs.h>
#include "Memory/SafeAllocator.h"

struct ByteHeader0204693c;
extern "C" void func_0204693c(struct ByteHeader0204693c* p);

// USA: func_ov017_021bac58
extern "C" ARM void func_ov017_021bac58(unsigned char* self) {
    func_0204693c((struct ByteHeader0204693c*)self);
    self[0] = 0xf;
    ((SafeAllocator*)(self + 0xc))->ResetAllocatorPointer();
    *(int*)(self + 8) = 0;
    *(int*)(self + 0x20) = 0;
    self[0x24] = 0xff;
}
