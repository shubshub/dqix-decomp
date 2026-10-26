#include <globaldefs.h>
#include "Memory/SafeAllocator.h"

struct ByteHeader0204693c { signed char byte0, unknown_1_, unknown_2_, unknown_3_; };
extern "C" void func_0204693c(ByteHeader0204693c* p);

// USA: func_ov017_021c2b28
extern "C" ARM void func_ov017_021c2b28(void* objRaw, unsigned char a, unsigned char b) {
    unsigned char* obj = (unsigned char*)objRaw;
    func_0204693c((ByteHeader0204693c*)obj);
    obj[0] = 0x46;
    ((SafeAllocator*)(obj + 8))->ResetAllocatorPointer();
    obj[0x8c] = 0;
    obj[0x8d] = 0;
    *(int*)(obj + 0x90) = 0;
    obj[0x96] = 0;
    obj[0x94] = a;
    obj[0x95] = b;
}
