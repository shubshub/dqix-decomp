#include <globaldefs.h>
#include "Filesystem/BackgroundLoader.h"
#include "std_library_functions.h"
#include "Resource/Brightness.h"

extern "C" int func_ov017_021959b4(void);
extern "C" void func_ov011_02184604(void* self, unsigned char* node);

struct Struct_02074bd0;
extern "C" void func_02074bd0(struct Struct_02074bd0* obj);
struct Struct_02074bf4;
extern "C" void func_02074bf4(struct Struct_02074bf4* obj);

void CleanInvalidateCacheRange(const void* addr, unsigned int size);
extern "C" int LoadToMainBG1CharacterData(int arg0, int arg1, unsigned int arg2);
extern "C" void LoadToMainBG1ScreenData(void* p, int a, int b);
extern "C" int func_ov023_021f6bb8(void* obj);

extern char g_fileLoadBuffer[];

// USA: func_ov011_02184770
extern "C" ARM void func_ov011_02184770(char* self) {
    if (func_ov017_021959b4() != 0 && *(void(**)(void*))(self + 0x1dc) != 0) {
        (*(void(**)(void*))(self + 0x1dc))(self);
    }
    *(void**)(self + 0x1dc) = 0;
    func_ov011_02184604(self, (unsigned char*)self);

    volatile unsigned int* var0 = (volatile unsigned int*)0x4000000;
    *var0 = (*var0 & ~0x1f00) | 0x100;

    func_02074bd0((struct Struct_02074bd0*)(self + 0x194));
    func_02074bf4((struct Struct_02074bf4*)(self + 0x194));

    volatile unsigned short* var1 = (volatile unsigned short*)0x4000304;
    int var2 = *(int*)(self + 0x190);
    *var1 = (var2 << 15) | (*var1 & ~0x8000);

    BackgroundLoader::AddLockGlobal();
    BackgroundLoader::FreeAllocationsGlobal();

    void* buf = g_fileLoadBuffer;
    memset(buf, 0, 0x600);
    CleanInvalidateCacheRange(buf, 0x20);
    LoadToMainBG1CharacterData((int)buf, 0, 0x20);
    CleanInvalidateCacheRange(buf, 0x600);
    LoadToMainBG1ScreenData(buf, 0, 0x600);

    unsigned int var4 = *(unsigned int*)(self + 0x1a8);
    volatile unsigned int* var5 = (volatile unsigned int*)0x4000000;
    volatile unsigned int* var6 = (volatile unsigned int*)0x4001000;
    *var5 = (var4 << 8) | (*var5 & ~0x1f00);
    unsigned int var7 = *(unsigned int*)(self + 0x1ac);
    *var6 = (var7 << 8) | (*var6 & ~0x1f00);

    int var8 = (int)BackgroundLoader::GetInstance();
    int key = func_ov023_021f6bb8(self + 0x118);
    ((BackgroundLoader*)(var8))->RemoveTask((int)(key));

    BackgroundLoader::RemoveLockGlobal();
    ClearFlags04(GetGameResources(), 0xc0);
}
