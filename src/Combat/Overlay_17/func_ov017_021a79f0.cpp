#include <globaldefs.h>
#include "Resource/FontBankLoader.h"
#include "Memory/SafeAllocator.h"
#include "NitroSDK/Memory/AllocatorUnion.h"

extern "C" void ROMFilesystem_InitFileTables(void);
extern "C" void AllocatorUnion_Free(AllocatorUnion*, void*);
extern AllocatorUnion g_mainAllocator;

struct Struct_ov017_021a79f0 {
    unsigned char pad0[0x1c];
    int field1c;
#if defined(jpn)
    unsigned char pad2[0x1ec - 0x20];
#else
    unsigned char pad2[0x25c - 0x20];
#endif
    SafeAllocator allocator;
};

// USA: func_ov017_021a79f0
extern "C" ARM void func_ov017_021a79f0(struct Struct_ov017_021a79f0* self) {
    FontBankLoader* g = FontBankLoader_GetInstance();
    func_02094b38(g, 0x205);
    FontBankLoader_CancelLoads(g);

    void* handle = self->allocator.GetSignedAllocator();
    if (handle != NULL) {
        self->allocator.Destroy();
        AllocatorUnion_Free(&g_mainAllocator, handle);
    }

    ROMFilesystem_InitFileTables();
    *(volatile unsigned int*)0x4000000 = (*(volatile unsigned int*)0x4000000 & ~0x1f00) | (self->field1c << 8);
}
