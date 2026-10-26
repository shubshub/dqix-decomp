#include <globaldefs.h>
#include "Memory/SafeAllocator.h"

struct ByteHeader0204693c;
extern "C" void func_0204693c(ByteHeader0204693c* p);
extern int data_ov017_021d8474;

struct Struct_ov017_021c0124 {
    unsigned char byte0;
    unsigned char pad1[7];
    SafeAllocator alloc;
    int f1c;
    unsigned char unknown_20_;
};

// USA: func_ov017_021c0124
extern "C" ARM void func_ov017_021c0124(Struct_ov017_021c0124* p, unsigned char flag) {
    func_0204693c((ByteHeader0204693c*)p);
    p->byte0 = 0x20;
    p->alloc.ResetAllocatorPointer();
    data_ov017_021d8474 = 0;
    p->f1c = 0;
    p->unknown_20_ = flag;
}
