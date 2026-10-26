#include <globaldefs.h>
#include "Memory/SafeAllocator.h"

extern "C" void func_ov003_0217db88(void);
extern "C" int func_020a1e54(int a);
extern "C" void AllocatorUnion_Free(AllocatorUnion* alloc, void* data);
extern int g_mainAllocator;
extern "C" void ROMFilesystem_InitFileTables(void);

struct Struct_020dae08 {
    char pad0;
    char field1;
    char pad2[0xc - 2];
    int unknown_c_;
    char pad3[0x14 - 0xc - 4];
    SafeAllocator allocator;
};

// USA: func_020dae08
extern "C" ARM void func_020dae08(struct Struct_020dae08* self) {
    if (self->unknown_c_ != 0) {
        func_ov003_0217db88();
        self->unknown_c_ = 0;
        func_020a1e54(1);
    }
    void* p = self->allocator.GetSignedAllocator();
    if (p != NULL) {
        self->allocator.Destroy();
        AllocatorUnion_Free((AllocatorUnion*)&g_mainAllocator, p);
    }
    ROMFilesystem_InitFileTables();
    self->field1 = 1;
}
