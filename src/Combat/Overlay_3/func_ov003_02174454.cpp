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

extern "C" int MessageSystem_GetInstance();

struct Struct_02074bd0;
extern "C" void func_02074bd0(struct Struct_02074bd0* obj);

void CleanInvalidateCacheRange(const void* addr, unsigned int size);
extern "C" int LoadToMainBG1CharacterData(int arg0, int arg1, unsigned int arg2);

// USA: func_ov003_02174454
extern "C" ARM void func_ov003_02174454(char* self) {
    unsigned char i;

    int data4 = (int)BackgroundLoader::GetInstance();
    if (*(int*)(self + Enum_ov003_02174454_4076) >= 0) {
        ((BackgroundLoader*)(data4))->RemoveTask((int)(*(int*)(self + Enum_ov003_02174454_4076)));
        *(int*)(self + Enum_ov003_02174454_4076) = -1;
    }

    unsigned char* g = (unsigned char*)MessageSystem_GetInstance();
    *(int*)(g + Enum_ov003_02174454_728) = 0;
    g[Enum_ov003_02174454_742] = 1;

    unsigned int* reg = (unsigned int*)0x4000000;
    *reg = (*reg & ~0x1f00) | 0x100;
    *(unsigned short*)0x4000050 = 0;
    func_02074bd0((struct Struct_02074bd0*)(self + 0x24));

#if !defined(jpn)
    if (*(void**)(self + Enum_ov003_02174454_4084) != 0)
#endif
    {
        memset(*(void**)(self + Enum_ov003_02174454_4084), 0, 0x20);
        CleanInvalidateCacheRange(*(void**)(self + Enum_ov003_02174454_4084), 0x20);
        LoadToMainBG1CharacterData((int)*(void**)(self + Enum_ov003_02174454_4084), 0, 0x20);
    }
    *(void**)(self + Enum_ov003_02174454_4084) = 0;

    if (*(void**)(self + 4) == 0) return;

    for (i = 0; i < 6; i++) {
        ((SafeAllocator*)(*(char**)(self + 4) + i * 0x14))->Destroy();
    }
}
