#include <globaldefs.h>
#include "Memory/SafeAllocator.h"
#include "NitroSDK/Memory/AllocatorUnion.h"

void PopStack0AndTrigger_020a1e54(int flag);
void AllocatorUnion_Free(AllocatorUnion* alloc, void* data);
extern int g_mainAllocator;

struct Obj0217e36c {
    char pad[0xc];
    SafeAllocator allocator;
    int f20;
};

// USA: func_ov003_0217e36c  (semantic: PopAndForwardAllocator_0217e36c)
extern "C" ARM void func_ov003_0217e36c(Obj0217e36c* self) {
    if (self->f20 != 0) {
        PopStack0AndTrigger_020a1e54(1);
        self->f20 = 0;
    }
    void* p = self->allocator.GetSignedAllocator();
    self->allocator.Destroy();
    AllocatorUnion_Free((AllocatorUnion*)&g_mainAllocator, p);
}
