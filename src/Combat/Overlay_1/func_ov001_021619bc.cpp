#include <globaldefs.h>
#include "Memory/SafeAllocator.h"
#include "Resource/GameResources.h"

extern "C" void func_020a1ef0(int id);
extern SafeAllocator* data_ov001_021658b8[1];
extern "C" void func_ov028_021d8b90(void* obj);
extern "C" void func_ov028_021d8b44(void* obj, SafeAllocator* allocator);

// USA: func_ov001_021619bc
extern "C" ARM int func_ov001_021619bc(void) {
#if defined(jpn)
    enum { Enum_ov001_021619bc_1844 = 0x524, objectOffset = 0x15c, flagOffset = 0x160 };
#else
    enum { Enum_ov001_021619bc_1844 = 0x734, objectOffset = 0x160, flagOffset = 0x164 };
#endif
    func_020a1ef0(5);
    char* p = *(char**)((char*)GetGameResources() + 0x3000 + Enum_ov001_021619bc_1844);
    void* newObj = data_ov001_021658b8[0]->Allocate(0x84);
    if (newObj == 0) return 0;
    *(void**)(p + objectOffset) = newObj;
    *(unsigned char*)(p + flagOffset) = 0;
    func_ov028_021d8b90(newObj);
    func_ov028_021d8b44(newObj, data_ov001_021658b8[0]);
    return 1;
}
