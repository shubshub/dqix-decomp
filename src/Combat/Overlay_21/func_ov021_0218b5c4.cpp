#include <globaldefs.h>
#include "Memory/SafeAllocator.h"
#include "NitroSDK/Memory/AllocatorUnion.h"

extern "C" void AllocatorUnion_Free(AllocatorUnion*, void*);
extern AllocatorUnion g_mainAllocator;

struct Struct_02000c9c_10 {
    char pad[0x2c];
    SafeAllocator allocator;
    char pad2[0x40 - 0x2c - sizeof(SafeAllocator)];
    int field40;
};

// USA: func_ov021_0218b5c4
extern "C" ARM void func_ov021_0218b5c4(struct Struct_02000c9c_10* self) {
    void* handle = self->allocator.GetSignedAllocator();
    self->allocator.Destroy();
    AllocatorUnion_Free(&g_mainAllocator, handle);
    self->field40 = 0;
}
