#include <globaldefs.h>
#include "Filesystem/BackgroundLoader.h"
#include "NitroSDK/Memory/AllocatorUnion.h"

struct Struct02012dd0;
unsigned int AllocatorUnion_GetMaxPossibleAllocation(struct Struct02012dd0* self);



struct NitroHandle;
NitroHandle* NitroHandle_FindBySignature(const char* sig, int a);
void NitroHandle_ReleaseFileTables(NitroHandle* h);

void AllocatorUnion_Free(AllocatorUnion* alloc, void* data);

struct Obj0202f9b4;

extern struct Struct02012dd0 g_mainAllocator;
extern void* data_02109d90;
extern const char data_020f18e8[];

// USA: func_020a0cc4  (semantic: TryReclaimAndForward020a0cc4)
extern "C" ARM int func_020a0cc4(int id) {
    if (id >= 0) {
        unsigned int max = AllocatorUnion_GetMaxPossibleAllocation(&g_mainAllocator);
        if (max >= id) goto fail;
    }
    if (data_02109d90 == NULL) goto fail;

    {
        int field4Val = (int)BackgroundLoader::GetInstance();
        if (field4Val != 0) {
            ((BackgroundLoader*)(field4Val))->Suspend();
        }

        NitroHandle_ReleaseFileTables(NitroHandle_FindBySignature(data_020f18e8, 3));
        AllocatorUnion_Free((AllocatorUnion*)&g_mainAllocator, data_02109d90);
        data_02109d90 = NULL;

        if (field4Val != 0) {
            ((BackgroundLoader*)((struct Obj0202f9b4*)field4Val))->RemoveLock();
        }
    }
    return 1;
fail:
    return 0;
}
