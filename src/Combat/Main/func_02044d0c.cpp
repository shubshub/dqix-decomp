#include <globaldefs.h>
#include "std_library_functions.h"
#include "Graphics/VRAMStaging.h"
#include "Combat/MapDisplay.h"
#include "Resource/GameResources.h"

extern char data_02107800;

extern "C" void Background_Init(struct BackgroundGraphics*);
extern "C" void Background_LoadFile(void* list, void* rec, void* alloc, int size);
extern "C" unsigned int GetMainBG1ScreenBase(void);
extern "C" void ColorEffect_ConfigureAlphaBlend(void* reg, int a, int b, int c, int d);

#if defined(jpn)
#define BG_UPLOAD_SOURCE_OFFSET 0x3c0
#define BG_UPLOAD_SIZE 0x280
#else
#define BG_UPLOAD_SOURCE_OFFSET 0x280
#define BG_UPLOAD_SIZE 0x900
#endif

// USA: func_02044d0c
extern "C" ARM void func_02044d0c(void) {
    volatile unsigned int* var0 = (volatile unsigned int*)0x04000000;
    volatile unsigned short* var1 = (volatile unsigned short*)0x04000000;

    var0[0] = (var0[0] & ~0x1f00u) | 0x1100u;
    var0[6] = 0;
    var0[7] = 0;
    var1[5] = (var1[5] & 0x43) | 0x1d00;
    var1[6] = (var1[6] & 0x43) | 0x1e00;
    var1[7] = (var1[7] & 0x43) | 0x308 | 0x1c00;

#if defined(jpn)
    char* base = *(char**)(&data_02107800 + 0x30);
#else
    char* base = *(char**)&data_02107800;
#endif
    char* rec = *(char**)((char*)GetGameResources() + 0x2c);

    struct BackgroundGraphics local;
    Background_Init(&local);
    local.subScreen_ = 0;
    local.bgNumber_ = 3;
    Background_LoadFile(&local, rec, 0, 0);

    if (base != 0) {
        unsigned char i;
        memset(base, 0, 0x1000);
        for (i = 0; i < 6; i++) {
            StageMemoryToVRAM(VRAMSubregion_MainBG3Character, base, i << 12, 0x1000, 1, 0);
        }
        char* p = *(char**)(&data_02107800 + 4);
        if (p + BG_UPLOAD_SOURCE_OFFSET != 0) {
            StageMemoryToVRAM(VRAMSubregion_MainBG2Character, p + BG_UPLOAD_SOURCE_OFFSET, 0x20, BG_UPLOAD_SIZE, 1, 0);
        }
    }

    if (base != 0) {
        unsigned short* w;
        unsigned short v;
        memset(base, 0, 0x1000);
        StageMemoryToVRAM(VRAMSubregion_MainBG2Screen, base, 0, 0x800, 1, 0);
        w = (unsigned short*)(base + 0x800);
        for (v = 0; v < 0x300; v++) {
            *w = v;
            w++;
        }
        StageMemoryToVRAM(VRAMSubregion_MainBG3Screen, base, 0, 0x800, 1, 0);
        unsigned int bg = GetMainBG1ScreenBase();
        if (bg != 0) {
            memset((void*)bg, 0, 0x800);
        }
    }

    ColorEffect_ConfigureAlphaBlend((void*)0x04000050, 4, 1, 0xa, 6);

    volatile unsigned short* var10 = (volatile unsigned short*)0x04000008;
    var10[0] = (var10[0] & ~3u) | 3u;
    var10[1] = (var10[1] & ~3u) | 2u;
    var10[2] = (var10[2] & ~3u) | 1u;
    var10[3] = var10[3] & ~3u;
}
