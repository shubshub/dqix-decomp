#include <globaldefs.h>
#include "Memory/SafeAllocator.h"
#include "NitroSDK/Memory/AllocatorUnion.h"

extern "C" void* func_02057924(void* obj);
extern "C" void func_02057f00(void* obj, int index);
void AllocatorUnion_Free(AllocatorUnion* alloc, void* data);
void NNS_GfdSetFrmTexVramState(int* out);
void NNS_GfdSetFrmPlttVramState(int* src);
extern "C" void ROMFilesystem_InitFileTables(void);

extern int g_mainAllocator;

struct Obj021a6b30 {
    char pad[0x10];
    SafeAllocator allocator;
};

// USA: func_ov017_021a6b30  (semantic: RestoreStateAndFinalize_021a6b30)
extern "C" ARM void func_ov017_021a6b30(struct Obj021a6b30* self) {
    func_02057f00(func_02057924(self), 0xc);

    void* p = self->allocator.GetSignedAllocator();
    if (p != NULL) {
        self->allocator.Destroy();
        AllocatorUnion_Free((AllocatorUnion*)&g_mainAllocator, p);
    }

    NNS_GfdSetFrmTexVramState((int*)((char*)self + 0x24));
    NNS_GfdSetFrmPlttVramState((int*)((char*)self + 0x4c));
    ROMFilesystem_InitFileTables();
}
