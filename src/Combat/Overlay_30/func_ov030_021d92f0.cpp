#include <globaldefs.h>
#include "Memory/AllocatorLifecycle.h"

struct AllocatorUnion;
extern "C" void AllocatorUnion_FreeUnlessZero(struct AllocatorUnion* alloc, void* ptr, int flag);

#if defined(jpn)
enum { BufferAllocationSize = 0x33f8 };
#else
enum { BufferAllocationSize = 0x36c0 };
#endif

// USA: func_ov030_021d92f0
extern "C" ARM void func_ov030_021d92f0(void* ptr, struct AllocatorUnion* alloc, void** slot) {
    if (ptr != NULL) {
        AllocatorUnion_FreeUnlessZero(alloc, ptr, 1);
    }
    if (*slot != NULL) {
        AllocatorUnion_FreeUnlessZero(alloc, *slot, BufferAllocationSize);
        *slot = NULL;
    }
    func_02012de4(alloc);
}
