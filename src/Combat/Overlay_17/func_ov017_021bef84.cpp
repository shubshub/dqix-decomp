#include <globaldefs.h>
#include "Memory/SafeAllocator.h"
#include "NitroSDK/Memory/AllocatorUnion.h"
#include "Resource/Brightness.h"

extern "C" void AllocatorUnion_Free(AllocatorUnion* alloc, void* data);

extern int g_mainAllocator;

struct Struct_ov017_021bef84 {
    char pad[0x44];
    SafeAllocator allocator;
};

// USA: func_ov017_021bef84
extern "C" ARM void func_ov017_021bef84(struct Struct_ov017_021bef84* self) {
    int h = (int)GetGameResources();
    void* p = self->allocator.GetSignedAllocator();
    if (p != NULL) {
        self->allocator.Destroy();
        AllocatorUnion_Free((AllocatorUnion*)&g_mainAllocator, p);
    }
    ClearFlags04((GameResources*)h, 0xc0);
}
