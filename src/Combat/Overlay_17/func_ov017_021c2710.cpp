#include <globaldefs.h>
#include "NitroSDK/Memory/AllocatorUnion.h"

extern AllocatorUnion g_mainAllocator;
extern "C" void AllocatorUnion_Free(AllocatorUnion* alloc, void* data);

// USA: func_ov017_021c2710
extern "C" ARM void func_ov017_021c2710(unsigned char* self) {
    void* p = *(void**)(self + 8);
    if (p != NULL) {
        AllocatorUnion_Free(&g_mainAllocator, p);
        *(void**)(self + 8) = NULL;
    }
    self[1] = 1;
}
