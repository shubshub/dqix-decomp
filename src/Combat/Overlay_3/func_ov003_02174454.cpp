#include <globaldefs.h>
#if defined(jpn)
enum { Enum_ov003_02174454_4076 = 0xf68 };
enum { Enum_ov003_02174454_4084 = 0xf70 };
enum { Enum_ov003_02174454_728 = 0x228 };
enum { Enum_ov003_02174454_742 = 0x236 };
#else
enum { Enum_ov003_02174454_4076 = 0xfec };
enum { Enum_ov003_02174454_4084 = 0xff4 };
enum { Enum_ov003_02174454_728 = 0x2d8 };
enum { Enum_ov003_02174454_742 = 0x2e6 };
#endif

#include "Filesystem/BackgroundLoader.h"
#include "Memory/SafeAllocator.h"
#include "std_library_functions.h"

int MessageSystem_GetInstance();

struct Struct_02074bd0;
extern "C" void func_02074bd0(struct Struct_02074bd0* arg0);

void CleanInvalidateCacheRange(const void* addr, unsigned int size);
extern "C" int LoadToMainBG1CharacterData(int arg0, int arg1, unsigned int arg2);

// USA: func_ov003_02174454
extern "C" ARM void func_ov003_02174454(char* arg0) {
    unsigned char var0;

    int var1 = (int)BackgroundLoader::GetInstance();
    if (*(int*)(arg0 + Enum_ov003_02174454_4076) >= 0) {
        ((BackgroundLoader*)(var1))->RemoveTask((int)(*(int*)(arg0 + Enum_ov003_02174454_4076)));
        *(int*)(arg0 + Enum_ov003_02174454_4076) = -1;
    }

    unsigned char* g = (unsigned char*)MessageSystem_GetInstance();
    *(int*)(g + kRegion2d8) = 0;
    g[kRegion2e6] = 1;

    unsigned int* var3 = (unsigned int*)0x4000000;
    *var3 = (*var3 & ~0x1f00) | 0x100;
    *(unsigned short*)0x4000050 = 0;
    func_02074bd0((struct Struct_02074bd0*)(arg0 + 0x24));

#if !defined(jpn)
    if (*(void**)(arg0 + Enum_ov003_02174454_4084) != 0)
#endif
    {
        memset(*(void**)(arg0 + Enum_ov003_02174454_4084), 0, 0x20);
        CleanInvalidateCacheRange(*(void**)(arg0 + Enum_ov003_02174454_4084), 0x20);
        LoadToMainBG1CharacterData((int)*(void**)(arg0 + Enum_ov003_02174454_4084), 0, 0x20);
    }
    *(void**)(arg0 + Enum_ov003_02174454_4084) = 0;

    if (*(void**)(arg0 + 4) == 0) return;

    for (var0 = 0; var0 < 6; var0++) {
        ((SafeAllocator*)(*(char**)(arg0 + 4) + var0 * 0x14))->Destroy();
    }
}
