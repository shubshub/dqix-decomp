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
extern "C" void func_02074bf4(struct Struct_02074bf4* arg0);
extern "C" int DisableSubBGVRAMBanks(void);
extern "C" void MapVRAMBanksToSubBG(int);
extern "C" void MapVRAMBanksToSubObj(int value);
struct BackgroundGraphics;
void Background_Destroy(struct BackgroundGraphics* obj);
struct Obj0204c754;
void ResetObject0204c754(struct Obj0204c754* obj);

// USA: func_ov003_02167370
extern "C" ARM void func_ov003_02167370(char* arg0) {
    int var0 = (int)BackgroundLoader::GetInstance();
    if (*(int*)(arg0 + Enum_ov003_02167370_100) >= 0) {
        ((BackgroundLoader*)(var0))->RemoveTask((int)(*(int*)(arg0 + Enum_ov003_02167370_100)));
        *(int*)(arg0 + Enum_ov003_02167370_100) = -1;
    }

    volatile unsigned int* var1 = (volatile unsigned int*)0x4001010;
    var1[0] = 0;
    var1[1] = 0;

    if (*(void**)(arg0 + 0x10) != 0) {
        func_0207f8bc(*(Struct_0207f7f0**)(arg0 + 0x10));
    }
    func_02074bf4((struct Struct_02074bf4*)(arg0 + 0x1c));

    volatile unsigned int* var2 = (volatile unsigned int*)0x4001000;
    *var2 = (*var2 & ~0x1f00) | (*(int*)(arg0 + Enum_ov003_02167370_96) << 8);

    DisableSubBGVRAMBanks();
    MapVRAMBanksToSubBG(*(int*)(arg0 + 0x14));
    MapVRAMBanksToSubObj(*(int*)(arg0 + 0x18));

    if (*(void**)(obj + 8) != 0) {
        Background_Destroy(*(struct BackgroundGraphics**)(obj + 8));
        *(int*)(obj + 8) = 0;
    }
    if (*(void**)(arg0 + 0xc) != 0) {
        func_0204c754(*(struct Struct_0204c754**)(arg0 + 0xc));
        *(int*)(arg0 + 0xc) = 0;
    }
    if (*(void**)(arg0 + 0x10) != 0) {
        func_0207f8bc(*(Struct_0207f7f0**)(arg0 + 0x10));
        *(int*)(arg0 + 0x10) = 0;
    }
    if (*(int*)arg0 != 0) {
        *(int*)arg0 = 0;
    }
    if (*(int*)(arg0 + 4) == 0) return;

    for (int var3 = 0; var3 < 3; var3++) {
        if (((SafeAllocator*)(*(char**)(arg0 + 4) + var3 * 0x14))->GetSignedAllocator() != 0) {
            ((SafeAllocator*)(*(char**)(arg0 + 4) + var3 * 0x14))->Destroy();
        }
    }
}
