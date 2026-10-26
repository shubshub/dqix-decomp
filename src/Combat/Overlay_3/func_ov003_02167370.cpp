#include <globaldefs.h>
#include "Combat/MenuNodeChain.h"
#include "Filesystem/BackgroundLoader.h"
#include "Memory/SafeAllocator.h"

#if defined(jpn)
enum { Enum_ov003_02167370_100 = 0x34 };
enum { Enum_ov003_02167370_96 = 0x30 };
#else
enum { Enum_ov003_02167370_100 = 0x64 };
enum { Enum_ov003_02167370_96 = 0x60 };
#endif

struct Struct_02074bf4;
extern "C" void func_02074bf4(struct Struct_02074bf4* obj);
extern "C" int DisableSubBGVRAMBanks(void);
extern "C" void MapVRAMBanksToSubBG(int);
extern "C" void MapVRAMBanksToSubObj(int value);
struct BackgroundGraphics;
extern "C" void Background_Destroy(struct BackgroundGraphics* obj);
struct Struct_0204c754;
extern "C" void func_0204c754(struct Struct_0204c754* obj);

// USA: func_ov003_02167370
extern "C" ARM void func_ov003_02167370(char* obj) {
    int data4 = (int)BackgroundLoader::GetInstance();
    if (*(int*)(obj + Enum_ov003_02167370_100) >= 0) {
        ((BackgroundLoader*)(data4))->RemoveTask((int)(*(int*)(obj + Enum_ov003_02167370_100)));
        *(int*)(obj + Enum_ov003_02167370_100) = -1;
    }

    volatile unsigned int* p1 = (volatile unsigned int*)0x4001010;
    p1[0] = 0;
    p1[1] = 0;

    if (*(void**)(obj + 0x10) != 0) {
        func_0207f8bc(*(Manager0207f7f0**)(obj + 0x10));
    }
    func_02074bf4((struct Struct_02074bf4*)(obj + 0x1c));

    volatile unsigned int* dispcnt = (volatile unsigned int*)0x4001000;
    *dispcnt = (*dispcnt & ~0x1f00) | (*(int*)(obj + Enum_ov003_02167370_96) << 8);

    DisableSubBGVRAMBanks();
    MapVRAMBanksToSubBG(*(int*)(obj + 0x14));
    MapVRAMBanksToSubObj(*(int*)(obj + 0x18));

    if (*(void**)(obj + 8) != 0) {
        Background_Destroy(*(struct BackgroundGraphics**)(obj + 8));
        *(int*)(obj + 8) = 0;
    }
    if (*(void**)(obj + 0xc) != 0) {
        func_0204c754(*(struct Struct_0204c754**)(obj + 0xc));
        *(int*)(obj + 0xc) = 0;
    }
    if (*(void**)(obj + 0x10) != 0) {
        func_0207f8bc(*(Manager0207f7f0**)(obj + 0x10));
        *(int*)(obj + 0x10) = 0;
    }
    if (*(int*)obj != 0) {
        *(int*)obj = 0;
    }
    if (*(int*)(obj + 4) == 0) return;

    for (int i = 0; i < 3; i++) {
        if (((SafeAllocator*)(*(char**)(obj + 4) + i * 0x14))->GetSignedAllocator() != 0) {
            ((SafeAllocator*)(*(char**)(obj + 4) + i * 0x14))->Destroy();
        }
    }
}
