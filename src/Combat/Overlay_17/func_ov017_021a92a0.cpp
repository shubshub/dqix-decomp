#include <globaldefs.h>
#include "Resource/FontBankLoader.h"
#include "Memory/SafeAllocator.h"
#include "NitroSDK/Memory/AllocatorUnion.h"
#include "Resource/Brightness.h"

extern "C" void AllocatorUnion_Free(AllocatorUnion*, void*);
extern AllocatorUnion g_mainAllocator;

struct Struct_ov017_021a92a0 {
    unsigned char pad0[0x24];
    int field24;
#if defined(jpn)
    unsigned char pad1[0x1f4 - 0x28];
#else
    unsigned char pad1[0x264 - 0x28];
#endif
    SafeAllocator allocator;
};

// USA: func_ov017_021a92a0
extern "C" ARM void func_ov017_021a92a0(struct Struct_ov017_021a92a0* self) {
    FontBankLoader* g = FontBankLoader_GetInstance();
    func_02094b38(g, 0x205);
    FontBankLoader_CancelLoads(g);

    void* handle = self->allocator.GetSignedAllocator();
    if (handle != NULL) {
        self->allocator.Destroy();
        AllocatorUnion_Free(&g_mainAllocator, handle);
    }

    ClearFlags04(GetGameResources(), 0x40);
    *(volatile unsigned int*)0x4000000 = (*(volatile unsigned int*)0x4000000 & ~0x1f00) | (self->field24 << 8);
}
