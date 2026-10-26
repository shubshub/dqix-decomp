#include <globaldefs.h>
#include "Combat/MapDisplay.h"
#include "Filesystem/BackgroundLoader.h"
#include "GameState/GameState.h"
#include "NitroSDK/BGBases.h"
#include "NitroSDK/Cache.h"
#include "NitroSDK/LoadToVRAM.h"
#include "std_library_functions.h"

struct Word0x0_0215e5b0 {
    char pad0[0x2c];
    void* record;
};

extern "C" void func_ov001_0215e758(int screenSize, int colorMode, int screenBase, int charBase, int bit13);
extern "C" void func_ov001_0215e78c(int screenSize, int colorMode, int screenBase, int charBase, int bit13);
extern "C" void Background_Init(struct BackgroundGraphics* obj);
extern "C" void Background_LoadFile(void* list, void* rec, void* alloc, int size);

extern char g_fileLoadBuffer[] __attribute__((aligned(4)));

// USA: func_ov001_0215e5b0
extern "C" ARM int func_ov001_0215e5b0(void) {
    BackgroundLoader::AddLockGlobal();
    BackgroundLoader::FreeAllocationsGlobal();
    struct Word0x0_0215e5b0* word = (Word0x0_0215e5b0*)GameState::GetInstance()->GetResources();

    char* buf = g_fileLoadBuffer;
    volatile unsigned int* dispcnt = (volatile unsigned int*)0x4001000;
    *dispcnt = (*dispcnt & ~0x1f00) | 0x300;
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

    struct BackgroundGraphics list;
    Background_Init(&list);
    list.subScreen_ = 1;
    Background_LoadFile(&list, word->record, 0, 0);

    unsigned int size = 0x6400;
    memset(buf, 0, size);
    memset(buf + 0x20, 0x11111111, 0x20);
    CleanInvalidateCacheRange(buf, size);
    LoadToSubBG0CharacterData(buf, 0, size);

    unsigned short* screen = (unsigned short*)GetSubBG0ScreenBase();
    unsigned short tile = 3;
    for (unsigned short i = 0; i < 0x300; i++) {
        *screen++ = tile;
        tile++;
    }

    screen = (unsigned short*)GetSubBG1ScreenBase();
    for (unsigned short i = 0; i < 0x300; i++) {
        *screen++ = 1;
    }

    BackgroundLoader::RemoveLockGlobal();
    return 1;
}
