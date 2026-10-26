#include <globaldefs.h>
#include "NitroSDK/Cache.h"
#include "Memory/SafeAllocator.h"
#include "std_library_functions.h"

extern "C" void LoadToMainBGStandardPalette(int src, int dstOffset, unsigned int size);
extern "C" void LoadToSubBGStandardPalette(int src, int dstOffset, unsigned int size);
int BgTransfers_LoadTiles(int* bgTransfers, int screen, int bg, int source, unsigned int size, unsigned int tileCount);

extern int data_02105254;

// A BG tile image: its file's 8-byte header, then what loading it set up
struct Obj0203bb3c {
    unsigned char width;      // in tiles
    unsigned char height;     // in tiles
    unsigned char colorMode;  // kColorMode16 or kColorMode256
    unsigned char pad3;
    int tileCount;
    void* map;                // copy of the file's screen map (width * height entries)
    char pad2[0x14 - 0xc];
    short firstTile;
    short screen;
    short bg;
};

enum {
    kColorMode16 = 0,      // 16-colour palette (0x20 bytes), 32-byte tiles
    kColorMode256 = 1,     // 256-colour palette (0x200 bytes), 64-byte tiles
    kPalette16Size = 0x20,
    kPalette256Size = 0x200
};

// Main, originally SetupAndDispatchCharTransfer0203bb3c (USA 0x0203bb3c, EUR 0x0203bb4c, JPN 0x0203b594)
ARM void BgImage_Load(struct Obj0203bb3c* image, char* data, SafeAllocator* allocator, int screen, unsigned short bg) {
    image->screen = screen;
    image->bg = bg;
    int* bgTransfers = (int*)&data_02105254;
    memcpy(image, data, 8);
    data += 8;

    if (image->colorMode == kColorMode16) {
        CleanInvalidateCacheRange(data, kPalette16Size);
        switch (screen) {
        case 0: LoadToMainBGStandardPalette((int)data, 0, kPalette16Size); break;
        case 1: LoadToSubBGStandardPalette((int)data, 0, kPalette16Size); break;
        }
        data += kPalette16Size;
        image->firstTile = (short)BgTransfers_LoadTiles(bgTransfers, screen, bg, (int)data, image->tileCount << 5, image->tileCount);
        data += image->tileCount << 5;
    } else if (image->colorMode == kColorMode256) {
        CleanInvalidateCacheRange(data, kPalette256Size);
        switch (screen) {
        case 0: LoadToMainBGStandardPalette((int)data, 0, kPalette256Size); break;
        case 1: LoadToSubBGStandardPalette((int)data, 0, kPalette256Size); break;
        }
        data += kPalette256Size;
        image->firstTile = (short)BgTransfers_LoadTiles(bgTransfers, screen, bg, (int)data, image->tileCount << 6, image->tileCount);
        data += image->tileCount << 6;
    }

    image->map = allocator->Allocate(image->height * (image->width * 2));
    memcpy(image->map, data, image->height * (image->width * 2));
}
