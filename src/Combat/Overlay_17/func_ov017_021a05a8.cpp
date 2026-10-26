#include <globaldefs.h>
#include "Memory/SafeAllocator.h"
#include "NitroSDK/Memory/AllocatorUnion.h"

extern "C" void* AllocatorUnion_AllocateRounded(AllocatorUnion* alloc, unsigned int size);
extern "C" void AllocatorUnion_Free(AllocatorUnion* alloc, void* data);

extern AllocatorUnion g_mainAllocator;

struct Struct_ov017_021d6874 { int index; int pad4; };
struct Struct_ov017_021d6878 { int size; int pad4; };
extern Struct_ov017_021d6874 data_ov017_021d6874[];
extern Struct_ov017_021d6878 data_ov017_021d6878[];

struct Struct_02000c9c_58 {
    char pad0[0x9c];
    SafeAllocator allocator;
};

// USA: func_ov017_021a05a8
extern "C" ARM void func_ov017_021a05a8(char* self) {
    SafeAllocator* var0 = (SafeAllocator*)(self + 0x9c);
    void* p = var0->GetSignedAllocator();
    if (p) {
        var0->Destroy();
        AllocatorUnion_Free(&g_mainAllocator, p);
    }

    self = self + 0x38;
    int i = 0;
    for (; data_ov017_021d6878[i].size != 0; i++) {
        int size = data_ov017_021d6878[i].size;
        void* buf = AllocatorUnion_AllocateRounded(&g_mainAllocator, size);
        int idx = data_ov017_021d6874[i].index;
        SafeAllocator* alloc = (SafeAllocator*)(self + idx * 0x14);
        alloc->CreateTypeA(buf, size);
    }
}
