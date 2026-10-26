#include <globaldefs.h>
#include "Memory/SafeAllocator.h"

struct ByteHeader0204693c;
extern "C" void func_0204693c(struct ByteHeader0204693c* p);

extern "C" void func_0208b9a0(void*, int);

struct Struct_02061c04_11;
extern "C" void func_ov017_021b994c(struct Struct_02061c04_11* obj);

// USA: func_ov017_021b8d1c
extern "C" ARM void func_ov017_021b8d1c(unsigned char* base) {
    func_0204693c((struct ByteHeader0204693c*)base);
    ((SafeAllocator*)(base + 0x8))->ResetAllocatorPointer();
    ((SafeAllocator*)(base + 0x1c))->ResetAllocatorPointer();
    func_0208b9a0(base + 0x30, 0);
    base[0] = 5;
    *(int*)(base + 0x11c) = 0;
    *(int*)(base + 0x124) = 0;
    *(int*)(base + 0x114) = 0;
    *(int*)(base + 0x118) = 0;
    base[0x128] = 0;
    base[0x129] = 0;
    base[0x137] = 0;
    base[0x138] = 0;
    base[0x139] = 0;
    func_ov017_021b994c((struct Struct_02061c04_11*)base);
}
