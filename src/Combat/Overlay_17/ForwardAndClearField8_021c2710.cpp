#include <globaldefs.h>
#include "NitroSDK/Memory/AllocatorUnion.h"

extern AllocatorUnion g_mainAllocator;
void AllocatorUnion_Free(AllocatorUnion* alloc, void* data);

// USA: func_ov017_021c2710
ARM void ForwardAndClearField8_021c2710(unsigned char* self) {
    void* p = *(void**)(self + 8);
    if (p != NULL) {
        AllocatorUnion_Free(&g_mainAllocator, p);
        *(void**)(self + 8) = NULL;
    }
    self[1] = 1;
}
