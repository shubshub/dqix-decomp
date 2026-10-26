#include <globaldefs.h>
#include "Memory/SafeAllocator.h"
#include "Resource/Brightness.h"

extern "C" void AllocatorUnion_Free(AllocatorUnion* alloc, void* data);
extern int g_mainAllocator;

// USA: func_ov017_021a9714
extern "C" ARM void func_ov017_021a9714(char* self) {
    SafeAllocator* allocator = (SafeAllocator*)(self + 0xc);
    void* p = allocator->GetSignedAllocator();
    if (p != NULL) {
        allocator->Destroy();
        AllocatorUnion_Free((AllocatorUnion*)&g_mainAllocator, p);
    }
    allocator->ResetAllocatorPointer();
    self[8] = 0;
    *(int*)(self + 0x20) = 0;
    void* h = GetGameResources();
    ClearFlags04((GameResources*)h, 0xc0);
}
