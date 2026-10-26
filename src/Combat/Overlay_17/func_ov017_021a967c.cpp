#include <globaldefs.h>
#include "NitroSDK/Memory.h"
#include "Memory/SafeAllocator.h"
#include "std_library_functions.h"

struct ByteHeader0204693c;
extern "C" void func_0204693c(struct ByteHeader0204693c* p);

struct Struct_ov017_021a967c { unsigned short unknown_0_0_ : 14; unsigned short unknown_1_6_ : 1; unsigned short unknown_1_7_ : 1; };

// USA: func_ov017_021a967c
extern "C" ARM void func_ov017_021a967c(unsigned char* self, int id) {
    func_0204693c((struct ByteHeader0204693c*)self);
    self[0x0] = 0x3a;
    ((SafeAllocator*)(self + 0xc))->ResetAllocatorPointer();
    self[0x8] = 0;
    *(int*)(self + 0x20) = 0;
    self[0x24] = id;
    self[0x9] = 0;
    self[0x25] = 0;
    self[0x26] = 0;
    VectorizedMemset(self + 0x28, 0, 6);
    memset(self + 0x2e, 0, 0xb);
    ((Struct_ov017_021a967c*)(self + 0x3a))->unknown_0_0_ = 0;
    self[0x39] = 0;
    ((Struct_ov017_021a967c*)(self + 0x3a))->unknown_1_6_ = 0;
    VectorizedMemset(self + 0x3c, 0, 0x18);
    *(int*)(self + 0x54) = 0;
}
