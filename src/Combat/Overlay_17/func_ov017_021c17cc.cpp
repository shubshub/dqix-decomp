#include <globaldefs.h>
#include "Memory/SafeAllocator.h"

struct ByteHeader0204693c;
extern "C" void func_0204693c(ByteHeader0204693c* p);

struct Struct_ov017_021c17cc {
    unsigned char byte0;
    unsigned char pad1[7];
    SafeAllocator alloc;
    unsigned char unknown_1c_;
    unsigned char unknown_1d_;
    unsigned char pad1e[2];
    int f20;
};

// USA: func_ov017_021c17cc
extern "C" ARM void func_ov017_021c17cc(Struct_ov017_021c17cc* p) {
    func_0204693c((ByteHeader0204693c*)p);
    p->byte0 = 0x2f;
    p->alloc.ResetAllocatorPointer();
    p->unknown_1c_ = 0;
    p->f20 = 0;
    p->unknown_1d_ = 0;
}
