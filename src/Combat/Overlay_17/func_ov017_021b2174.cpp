#include <globaldefs.h>
#include "Memory/SafeAllocator.h"

struct ByteHeader0204693c;
extern "C" void func_0204693c(struct ByteHeader0204693c* p);

extern int data_ov017_021d83f0[2];

// USA: func_ov017_021b2174
extern "C" ARM void func_ov017_021b2174(unsigned char* obj) {
    func_0204693c((struct ByteHeader0204693c*)obj);
    obj[0x0] = 0x2d;
    *(int*)(obj + 0x8) = 0;
    *(int*)(obj + 0xc) = -1;
    data_ov017_021d83f0[1] = 0;
    ((SafeAllocator*)(obj + 0x10))->ResetAllocatorPointer();

    struct Struct_ov017_021b2174 {
        unsigned int bit0 : 1;
        unsigned int unknown_0_1_ : 1;
        unsigned int bit2 : 1;
        unsigned int unknown_0_3_ : 1;
        unsigned int unknown_0_4_ : 1;
        unsigned int unknown_0_5_ : 1;
    };
    Struct_ov017_021b2174* flags = (Struct_ov017_021b2174*)(obj + 0x38);
    flags->bit0 = 0;
    flags->unknown_0_1_ = 0;
    flags->bit2 = 0;
    obj[0x24] = 0;
    *(int*)(obj + 0x30) = 0;
    flags->unknown_0_3_ = 1;
    flags->unknown_0_4_ = 0;
    flags->unknown_0_5_ = 0;

    obj[0x3c] = 0xff;
    obj[0x3d] = 0xff;
    obj[0x3e] = 0;
    *(int*)(obj + 0x40) = 0;
    *(int*)(obj + 0x44) = 0;
    obj[0x48] = 0;
}
