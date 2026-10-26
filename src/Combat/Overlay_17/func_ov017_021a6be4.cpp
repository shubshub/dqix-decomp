#include <globaldefs.h>
#include "Memory/SafeAllocator.h"

struct ByteHeader0204693c;
extern "C" void func_0204693c(struct ByteHeader0204693c* p);

struct Struct_020727d8 {
    void* entries;
    short capacity;
    short count;
};
extern "C" void func_020727d8(struct Struct_020727d8* list);

// USA: func_ov017_021a6be4
extern "C" ARM void func_ov017_021a6be4(unsigned char* self) {
    func_0204693c((struct ByteHeader0204693c*)self);
    self[0] = 0x3e;
    *(int*)(self + 8) = 0;
    *(int*)(self + 0x44) = -1;
    *(int*)(self + 0xc) = 0;
    self[0x10] = 0;
    func_020727d8((struct Struct_020727d8*)(self + 0x14));
    ((SafeAllocator*)(self + 0x1c))->ResetAllocatorPointer();
    ((SafeAllocator*)(self + 0x30))->ResetAllocatorPointer();
}
