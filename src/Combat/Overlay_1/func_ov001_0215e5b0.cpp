#include <globaldefs.h>
#include "Combat/MapDisplay.h"
#include "Filesystem/BackgroundLoader.h"
#include "GameState/GameState.h"
#include "NitroSDK/BGBases.h"
#include "NitroSDK/Cache.h"
#include "NitroSDK/LoadToVRAM.h"
#include "std_library_functions.h"

struct Struct_ov001_0215e5b0 {
    char unknown_0_[0x2c];
    void* unknown_2c_;
};

void SetSubBg0Control_0215e758(int screenSize, int colorMode, int screenBase, int charBase, int bit13);
void SetSubBg1Control_0215e78c(int screenSize, int colorMode, int screenBase, int charBase, int bit13);
void Background_Init(struct List0204af64* obj);
extern "C" void Background_LoadFile(void* list, void* rec, void* alloc, int size);

extern char data_0211e33c[] __attribute__((aligned(4)));

// USA: func_ov001_0215e5b0
extern "C" ARM int func_ov001_0215e5b0(void) {
    BackgroundLoader::AddLockGlobal();
    BackgroundLoader::FreeAllocationsGlobal();
    struct Word0x0_0215e5b0* word = (Word0x0_0215e5b0*)GameState::GetInstance()->GetResources();

    char* var1 = data_0211e33c;
    volatile unsigned int* var2 = (volatile unsigned int*)0x4001000;
    *var2 = (*var2 & ~0x1f00) | 0x300;
    func_ov001_0215e758(0, 0, 0xe, 0, 0);
    func_ov001_0215e78c(0, 0, 0xf, 0, 0);

    volatile unsigned short* var3 = (volatile unsigned short*)0x4001008;
    var3[0] = (var3[0] & ~3);
    var3[1] = (var3[1] & ~3) | 1;
    var3[2] = (var3[2] & ~3) | 2;
    var3[3] = (var3[3] & ~3) | 3;

    *(volatile unsigned int*)0x4000010 = 0;
    *(volatile unsigned int*)0x4000014 = 0;
    *(volatile unsigned short*)0x4001050 = 0;

    struct List0204af64 list;
    Background_Init(&list);
    list.b1c_lo = 1;
    Background_LoadFile(&list, word->record, 0, 0);

    unsigned int var5 = 0x6400;
    memset(var1, 0, var5);
    memset(var1 + 0x20, 0x11111111, 0x20);
    CleanInvalidateCacheRange(var1, var5);
    LoadToSubBG0CharacterData(var1, 0, var5);

    unsigned short* var6 = (unsigned short*)GetSubBG0ScreenBase();
    unsigned short var7 = 3;
    for (unsigned short var8 = 0; var8 < 0x300; var8++) {
        *var6++ = var7;
        var7++;
    }

    var6 = (unsigned short*)GetSubBG1ScreenBase();
    for (unsigned short var9 = 0; var9 < 0x300; var9++) {
        *var6++ = 1;
    }

    BackgroundLoader::RemoveLockGlobal();
    return 1;
}
