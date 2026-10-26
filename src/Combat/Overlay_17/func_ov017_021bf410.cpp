#include <globaldefs.h>
#include "Memory/SafeAllocator.h"

struct ByteHeader0204693c;
extern "C" void func_0204693c(struct ByteHeader0204693c* p);

// USA: func_ov017_021bf410
extern "C" ARM void func_ov017_021bf410(unsigned char* obj) {
    func_0204693c((struct ByteHeader0204693c*)obj);
    obj[0x0] = 0xd;
    obj[0xa] = 0;
    obj[0xb] = 0;
    *(int*)(obj + 0xc) = 0;
    *(int*)(obj + 0x10) = 0;
    *(short*)(obj + 0x14) = -1;
    *(short*)(obj + 0x16) = 0x3d;
    *(short*)(obj + 0x18) = 0;
    *(short*)(obj + 0x8) = 0;
    ((SafeAllocator*)(obj + 0x34))->ResetAllocatorPointer();
    ((SafeAllocator*)(obj + 0x4c))->ResetAllocatorPointer();

    unsigned int field = (*(volatile unsigned int*)0x4000000 & 0x1f00) >> 8;
    field |= 0x10;
    unsigned int cleared = *(volatile unsigned int*)0x4000000 & ~0x1f00;
    *(volatile unsigned int*)0x4000000 = cleared | (field << 8);

    obj[0x48] = 0;
}
