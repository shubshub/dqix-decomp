#include <globaldefs.h>
#include "Memory/SafeAllocator.h"

extern "C" void func_ov023_021e1330(void* obj);

// USA: func_ov002_0215b428
extern "C" ARM void func_ov002_0215b428(unsigned char* obj) {
    func_ov023_021e1330(obj + 0x4 + 0x800);
    ((SafeAllocator*)(obj + 0x850))->Reset();
    *(int*)(obj + 0x2000 + 0x534) = 0;
    *(int*)(obj + 0x2000 + 0x538) = 0;
}
