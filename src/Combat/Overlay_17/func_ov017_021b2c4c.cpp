#include <globaldefs.h>
#include "Combat/BattleHeapOwner.h"
#include "Memory/SafeAllocator.h"

struct ByteHeader0204693c;
extern "C" void func_0204693c(ByteHeader0204693c* p);

struct Struct_ov017_021b2c4c {
    unsigned char byte0;
    unsigned char pad0[7];
    int f8;
    SafeAllocator alloc;
};

// USA: func_ov017_021b2c4c
extern "C" ARM void func_ov017_021b2c4c(Struct_ov017_021b2c4c* p) {
    func_0204693c((ByteHeader0204693c*)p);
    p->byte0 = 0x12;
    p->alloc.ResetAllocatorPointer();
    p->f8 = 0;
    data_ov017_021d840c = 0;
    *((unsigned char*)p + 0x20) = 0xff;
}
