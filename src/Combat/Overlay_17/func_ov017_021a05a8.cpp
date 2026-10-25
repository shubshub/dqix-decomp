#include <globaldefs.h>
#include "Memory/SafeAllocator.h"
#include "NitroSDK/Memory/AllocatorUnion.h"

void* AllocatorUnion_AllocateRounded(AllocatorUnion* alloc, unsigned int size);
void AllocatorUnion_Free(AllocatorUnion* alloc, void* data);

extern AllocatorUnion g_mainAllocator;

struct Struct_ov017_021d6874 { int unknown_0_; int unknown_4_; };
struct Struct_ov017_021d6878 { int unknown_0_; int unknown_4_; };
extern Struct_ov017_021d6874 data_ov017_021d6874[];
extern Struct_ov017_021d6878 data_ov017_021d6878[];

struct Struct_02000c9c_58 {
    char unknown_0_[0x9c];
    SafeAllocator unknown_9c_;
};

// USA: func_ov017_021a05a8
extern "C" ARM void func_ov017_021a05a8(char* self) {
    SafeAllocator* topAlloc = (SafeAllocator*)(self + 0x9c);
    void* p = topAlloc->GetSignedAllocator();
    if (p) {
        topAlloc->Destroy();
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
