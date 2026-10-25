#include <globaldefs.h>
#include "World/ZoneLootableRecord.h"
#include "Memory/SafeAllocator.h"
#include "NitroSDK/Memory/AllocatorUnion.h"

struct Foo02048004;
extern void SprSprite_Unload(struct Foo02048004* obj);
extern void InitEightSubStructs_0202f1a4(char* obj);
extern void AllocatorUnion_Free(AllocatorUnion* alloc, void* data);

extern AllocatorUnion g_mainAllocator;

// USA: func_0202f1dc
ARM void ReinitEightSubStructsAndAllocator_0202f1dc(char* obj) {
    char* p;
    int i;
    p = obj;
    for (i = 0; i < 8; i++) {
        SprSprite_Unload((struct Foo02048004*)p);
        p += 0x88;
    }

    if (*(SafeAllocator**)(obj + 0x444) != NULL) {
        SignedAllocatorHeader* header = (*(SafeAllocator**)(obj + 0x444))->GetSignedAllocator();
        (*(SafeAllocator**)(obj + 0x444))->Destroy();
        AllocatorUnion_Free(&g_mainAllocator, header);
        AllocatorUnion_Free(&g_mainAllocator, *(SafeAllocator**)(obj + 0x444));
    }

    InitEightSubStructs_0202f1a4(obj);
}
