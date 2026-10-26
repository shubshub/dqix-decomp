#include <globaldefs.h>
#include "Memory/SafeAllocator.h"

#if defined(jpn)
enum { Enum_ov003_0215f8cc_552 = 0x110 };
enum { Enum_ov003_0215f8cc_572 = 0x124 };
enum { Enum_ov003_0215f8cc_612 = 0x14c };
enum { Enum_ov003_0215f8cc_632 = 0x160 };
enum { Enum_ov003_0215f8cc_652 = 0x174 };
enum { Enum_ov003_0215f8cc_672 = 0x188 };
enum { Enum_ov003_0215f8cc_692 = 0x19c };
enum { Enum_ov003_0215f8cc_712 = 0x1b0 };
#else
enum { Enum_ov003_0215f8cc_552 = 0x228 };
enum { Enum_ov003_0215f8cc_572 = 0x23c };
enum { Enum_ov003_0215f8cc_612 = 0x264 };
enum { Enum_ov003_0215f8cc_632 = 0x278 };
enum { Enum_ov003_0215f8cc_652 = 0x28c };
enum { Enum_ov003_0215f8cc_672 = 0x2a0 };
enum { Enum_ov003_0215f8cc_692 = 0x2b4 };
enum { Enum_ov003_0215f8cc_712 = 0x2c8 };
#endif


// USA: func_ov003_0215f8cc
extern "C" ARM void func_ov003_0215f8cc(void* self, SafeAllocator* other) {
    if (other == 0) return;

    void* buf = other->Allocate(0x1000);
    ((SafeAllocator*)((char*)self + Enum_ov003_0215f8cc_552))->CreateTypeA(buf, 0x1000);

    buf = other->Allocate(0x7000);
    ((SafeAllocator*)((char*)self + Enum_ov003_0215f8cc_572))->CreateTypeA(buf, 0x7000);

    buf = other->Allocate(0x2000);
    ((SafeAllocator*)((char*)self + Enum_ov003_0215f8cc_612))->CreateTypeA(buf, 0x2000);

    buf = other->Allocate(0x7400);
    ((SafeAllocator*)((char*)self + Enum_ov003_0215f8cc_632))->CreateTypeA(buf, 0x7400);

    buf = other->Allocate(0x4c00);
    ((SafeAllocator*)((char*)self + Enum_ov003_0215f8cc_652))->CreateTypeA(buf, 0x4c00);

    buf = other->Allocate(0xc00);
    ((SafeAllocator*)((char*)self + Enum_ov003_0215f8cc_672))->CreateTypeA(buf, 0xc00);

    buf = other->Allocate(0x3c00);
    ((SafeAllocator*)((char*)self + Enum_ov003_0215f8cc_692))->CreateTypeA(buf, 0x3c00);

    buf = other->Allocate(0x200);
    ((SafeAllocator*)((char*)self + Enum_ov003_0215f8cc_712))->CreateTypeA(buf, 0x200);
}
