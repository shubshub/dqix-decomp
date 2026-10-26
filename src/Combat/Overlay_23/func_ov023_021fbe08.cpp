#include <globaldefs.h>
#include "Memory/SafeAllocator.h"

extern "C" void func_ov023_021f6ed8(void*);
extern "C" void ItemTable_Init(void* obj);

// USA: func_ov023_021fbe08
extern "C" ARM int func_ov023_021fbe08(void* obj, void* unused, short arg2, short arg3, void* arg4) {
    func_ov023_021f6ed8(obj);
    *(unsigned short*)((char*)obj + 0x4) = 0x11;
    *(unsigned short*)((char*)obj + 0x6) = arg2;
    *(unsigned short*)((char*)obj + 0x8) = arg3;
    ItemTable_Init((char*)obj + 0x34);
    *(void**)((char*)obj + 0x4c) = arg4;
    ((SafeAllocator*)((char*)obj + 0x20))->ResetAllocatorPointer();
    return 1;
}
