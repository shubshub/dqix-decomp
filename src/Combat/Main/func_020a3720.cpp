#include <globaldefs.h>
#include "Filesystem/BackgroundLoader.h"
#include "GameState/GameState.h"
#include "Filesystem/FileIO.h"
#include "NitroSDK/Memory.h"
#include "std_library_functions.h"
#include "Resource/GameResources.h"


extern "C" void func_020a395c(void);
int AllocateIndexedSlot020a36cc(void** out, unsigned int idx);
extern "C" void HaltSystem(void);

#if defined(jpn)
extern const char data_020f1bf4[];
#endif
extern const char data_020f1a9c[];
extern const char data_020f1ab0[];

// USA: func_020a3720
extern "C" ARM int func_020a3720(void) {
    GameState* var0 = GameState::GetInstance();
    int var1 = ((int)GetGameResources());
    unsigned char* var2 = var0->GetTreasureMapLanguageData();
    if (var2 != 0 || *(void**)(var1 + 0x4000 + (
#if defined(jpn)
0x1dc
#else
0x48c
#endif
)) != 0) {
        func_020a395c();
    }

    if (!func_020a36cc((void**)&var2, 0x2000)) return 0;
    if (!func_020a36cc((void**)(var1 + 0x4000 + (
#if defined(jpn)
0x1dc
#else
0x48c
#endif
)), 0x44)) return 0;

    unsigned int var3 = 0;
#if defined(jpn)
    if (!LoadFileIntoMemory(data_020f1bf4, var2, &var3)) return 0;
#else
    BackgroundLoader::AddLockGlobal();
    void* extracted = ExtractFileFromGP2(data_020f1a9c, data_020f1ab0, &fileSize);
    memcpy(buf, extracted, fileSize);
    if (fileSize > 0x2000) {
        HaltSystem();
    }

#endif
    unsigned int var5 = 0;
    unsigned int var6 = 0;
    VectorizedInvertedMemcpy(var2, &var6, 4);
    var5 += 4;
    unsigned int var7 = 0;
    while (var7 < var6) {
        VectorizedInvertedMemcpy(var2 + var5, *(unsigned char**)((unsigned char*)var1 + 0x4000 + (
#if defined(jpn)
0x1dc
#else
0x48c
#endif
)) + var7 * 4, 4);
        var5 += 4;
        ++var7;
    }

#if !defined(jpn)
    BackgroundLoader::RemoveLockGlobal();
#endif
    var0->SetTreasureMapLanguageDataPtr(var2);
    return 1;
}
