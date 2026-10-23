#include <globaldefs.h>
#include "Memory/SafeAllocator.h"

extern "C" void func_ov023_021f6ed8(void*);
void ItemTable_Init(void* obj);

// USA: func_ov023_021fbe08  (semantic: InitObjFull_021fbe08)
extern "C" ARM int func_ov023_021fbe08(void* obj, void* unused, short arg3, short arg4, void* arg5) {
    func_ov023_021f6ed8(obj);
    *(unsigned short*)((char*)obj + 0x4) = 0x11;
    *(unsigned short*)((char*)obj + 0x6) = arg3;
    *(unsigned short*)((char*)obj + 0x8) = arg4;
    ItemTable_Init((char*)obj + 0x34);
    *(void**)((char*)obj + 0x4c) = arg5;
    ((SafeAllocator*)((char*)obj + 0x20))->ResetAllocatorPointer();
    return 1;
}
