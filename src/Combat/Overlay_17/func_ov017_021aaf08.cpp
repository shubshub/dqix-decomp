#include <globaldefs.h>
#include "Combat/MenuNodeChain.h"
#include "Filesystem/BackgroundLoader.h"
#include "Memory/SafeAllocator.h"
#include "NitroSDK/Memory/AllocatorUnion.h"
#include "std_library_functions.h"
#include "Resource/Brightness.h"

extern "C" void* GlobalFlags_GetInstance(void);
extern "C" void FlagWord_ClearBits(struct FlagWord020466f4* word, unsigned int mask);
extern "C" void AllocatorUnion_Free(AllocatorUnion* alloc, void* data);
void CleanInvalidateCacheRange(const void* addr, unsigned int size);
extern "C" int LoadToMainBG1CharacterData(int arg0, int arg1, unsigned int arg2);
extern "C" int LoadToMainBG2CharacterData(int arg0, int arg1, unsigned int arg2);
extern "C" void LoadToMainBG1ScreenData(void* p, int a, int b);
extern "C" int LoadToMainBG2ScreenData(int arg0, int arg1, unsigned int arg2);

extern int g_mainAllocator;

// USA: func_ov017_021aaf08
extern "C" ARM void func_ov017_021aaf08(char* self) {
    int var0 = (int)BackgroundLoader::GetInstance();
    if (*(int*)(self + 0x50) >= 0) {
        ((BackgroundLoader*)(var0))->RemoveTask((int)(*(int*)(self + 0x50)));
        *(int*)(self + 0x50) = -1;
    }

    if (*(void**)(self + 0x18) != 0) {
        func_0207f8bc(*(Manager0207f7f0**)(self + 0x18));
        *(void**)(self + 0x18) = 0;
    }

    int h = (int)GetGameResources();
    void* d = GlobalFlags_GetInstance();
    ClearFlags04((GameResources*)h, 0x80);
    FlagWord_ClearBits((struct FlagWord020466f4*)d, 0x200);

    SafeAllocator* allocator = (SafeAllocator*)(self + 0x24);
    void* p = allocator->GetSignedAllocator();
    allocator->Destroy();
    if (p) {
        AllocatorUnion_Free((AllocatorUnion*)&g_mainAllocator, p);
    }

    int buf = *(int*)(self + 0x8);
    if (buf != 0) {
        memset((void*)buf, 0, 0x800);
        CleanInvalidateCacheRange(*(void**)(self + 0x8), 0x800);
        LoadToMainBG1CharacterData(*(int*)(self + 0x8), 0, 0x20);
        LoadToMainBG2CharacterData(*(int*)(self + 0x8), 0, 0x20);
        LoadToMainBG1ScreenData(*(void**)(self + 0x8), 0, 0x800);
        LoadToMainBG2ScreenData(*(int*)(self + 0x8), 0, 0x800);
        *(int*)(self + 0x8) = 0;
    }
    *(int*)(self + 0x64) = 0;
}
