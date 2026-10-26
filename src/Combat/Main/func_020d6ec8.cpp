#include <globaldefs.h>
#include "Memory/SafeAllocator.h"

struct Struct_020d6ec8;
extern "C" void func_020d6f44(Struct_020d6ec8* c);

// USA: func_020d6ec8
extern "C" ARM void func_020d6ec8(Struct_020d6ec8* c, SafeAllocator* arg1) {
    ((SafeAllocator*)((char*)c + 0xa28))->ResetAllocatorPointer();
    void* buf = arg1->Allocate(0x6000);
    ((SafeAllocator*)((char*)c + 0xa28))->CreateTypeA(buf, 0x6000);
    func_020d6f44(c);
}
