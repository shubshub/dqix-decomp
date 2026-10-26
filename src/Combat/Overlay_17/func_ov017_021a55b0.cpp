#include <globaldefs.h>
#include "Memory/SafeAllocator.h"
#include "NitroSDK/Memory/AllocatorUnion.h"

extern "C" void AllocatorUnion_Free(AllocatorUnion* alloc, void* data);
extern "C" void ROMFilesystem_InitFileTables(void);
struct ResetObj020d7a5c;
extern "C" struct ResetObj020d7a5c* TextQueue_GetInstance();
struct Obj020d7aa0;
extern "C" void TextQueue_Reset(struct Obj020d7aa0* obj);

extern int g_mainAllocator;

struct Struct_ov017_021a55b0 {
    char pad[0x8];
    int field8;
    SafeAllocator allocator;
};

// USA: func_ov017_021a55b0
extern "C" ARM void func_ov017_021a55b0(struct Struct_ov017_021a55b0* self) {
    void* p = self->allocator.GetSignedAllocator();
    if (p != NULL) {
        self->allocator.Destroy();
        AllocatorUnion_Free((AllocatorUnion*)&g_mainAllocator, p);
        ROMFilesystem_InitFileTables();
    }
    TextQueue_Reset((struct Obj020d7aa0*)TextQueue_GetInstance());
    self->allocator.ResetAllocatorPointer();
    self->field8 = 0;
}
