#if defined(jpn)
enum { RegionOffset8c = 0x4c };
#else
enum { RegionOffset8c = 0x8c };
#endif

#include <globaldefs.h>
#include "Filesystem/BackgroundLoader.h"
#include "Memory/SafeAllocator.h"
#include "NitroSDK/Memory/AllocatorUnion.h"
#include "Resource/GameResources.h"

extern "C" int MessageSystem_GetInstance();
struct Struct_0208ba54;
extern "C" void func_0208ba54(struct Struct_0208ba54* self);
extern "C" void AllocatorUnion_Free(AllocatorUnion* alloc, void* data);
extern "C" void func_ov008_021845ac(void* p);
extern "C" void func_020dc2d0(int mode);
struct GameResources;
void SetSubBrightness(GameResources*, int, int);
struct Struct_02061c04_11;
extern "C" void func_ov017_021b994c(struct Struct_02061c04_11* obj);
extern "C" void ROMFilesystem_InitFileTables(void);

extern int g_mainAllocator;

// USA: func_ov017_021b8d80
extern "C" ARM void func_ov017_021b8d80(unsigned char* self) {
    GameResources* handle = GetGameResources();
    if (*(int*)(self + 0x120) > -1) {
        int field4 = (int)BackgroundLoader::GetInstance();
        ((BackgroundLoader*)(field4))->RemoveTask((int)(*(int*)(self + 0x120)));
    }

    if (self[0x137] == 0) {
        *(int*)((char*)MessageSystem_GetInstance() + RegionOffset8c) = 0;
        func_0208ba54((struct Struct_0208ba54*)(self + 0x30));
        SafeAllocator* allocA = (SafeAllocator*)(self + 0x8);
        void* pA = allocA->GetSignedAllocator();
        if (pA) {
            allocA->Destroy();
            AllocatorUnion_Free((AllocatorUnion*)&g_mainAllocator, pA);
        }
    }

    if (self[0x128] != 0) {
        func_ov008_021845ac(*(void**)(self + 0x118));
        SafeAllocator* var4 = (SafeAllocator*)(self + 0x1c);
        void* pB = var4->GetSignedAllocator();
        if (pB) {
            var4->Destroy();
            AllocatorUnion_Free((AllocatorUnion*)&g_mainAllocator, pB);
        }
        *(int*)(self + 0x118) = 0;

        volatile unsigned short* reg = (volatile unsigned short*)0x4001008;
        reg[0] = (reg[0] & ~3) | 1;
        reg[1] = (reg[1] & ~3) | 2;
        reg[2] = reg[2] & ~3;

        func_020dc2d0(0);
        SetSubBrightness(handle, 0, 0xf);
    }

    func_ov017_021b994c((struct Struct_02061c04_11*)self);
    ROMFilesystem_InitFileTables();
}
