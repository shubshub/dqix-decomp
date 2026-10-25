#include <globaldefs.h>
#include "Memory/SafeAllocator.h"
#include "NitroSDK/Memory/AllocatorUnion.h"

void PopStack1AndTrigger_020a1f4c(int flag);
void AllocatorUnion_Free(AllocatorUnion* alloc, void* data);

extern int g_mainAllocator;

// USA: func_ov017_021c07d0  (semantic: ResetFlagAndDestroyAllocator_021c07d0)
extern "C" ARM void func_ov017_021c07d0(char* self) {
    int* flag = (int*)(self + 0x1c);
    if (*flag != 0) {
        PopStack1AndTrigger_020a1f4c(1);
        *flag = 0;
    }
    SafeAllocator* alloc = (SafeAllocator*)(self + 0x8);
    void* p = alloc->GetSignedAllocator();
    if (p == NULL) return;
    alloc->Destroy();
    AllocatorUnion_Free((AllocatorUnion*)&g_mainAllocator, p);
}
