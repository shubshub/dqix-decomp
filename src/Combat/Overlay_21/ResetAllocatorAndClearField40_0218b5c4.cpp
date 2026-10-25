#include <globaldefs.h>
#include "Memory/SafeAllocator.h"
#include "NitroSDK/Memory/AllocatorUnion.h"

void AllocatorUnion_Free(AllocatorUnion*, void*);
extern AllocatorUnion g_mainAllocator;

struct Obj0218b5c4 {
    char pad[0x2c];
    SafeAllocator allocator;
    char pad2[0x40 - 0x2c - sizeof(SafeAllocator)];
    int field40;
};

// USA: func_ov021_0218b5c4
ARM void ResetAllocatorAndClearField40_0218b5c4(struct Obj0218b5c4* self) {
    void* handle = self->allocator.GetSignedAllocator();
    self->allocator.Destroy();
    AllocatorUnion_Free(&g_mainAllocator, handle);
    self->field40 = 0;
}
