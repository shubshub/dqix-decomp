#include <globaldefs.h>
#if defined(jpn)
#define IS_JPN 1
#else
#define IS_JPN 0
#endif
#include "Filesystem/BackgroundLoader.h"
#include "Memory/SafeAllocator.h"
#include "std_library_functions.h"

struct State0xbb1c;
struct Obj0203bb3c;
struct Bcb8Params;

void BgImage_Clear(struct State0xbb1c* obj);
void BgImage_Load(struct Obj0203bb3c* obj, char* src, SafeAllocator* allocator, int category, unsigned short arg5);
void BgImage_Place(struct Bcb8Params* s, int arg1, int arg2);
int BgTransfers_LoadTiles(int* arr1, int idx, int category, int addr, unsigned int len, unsigned int len2);
void* BgVram_GetInstance(void);

// The MapDisplay fields this reads (header: displayMode, forwardingFill, unknown78): +0x78 is a BG tile image that
// BgImage_Load loads (8-byte header: width and height in tiles; then palette, tiles and
// screen map) and that BgImage_Place places on the screen
struct MapDisplayPattern_02020fc4 {
    char pad0[0x14];
    int displayMode;
    char pad18[0x5c];
    int blankTile;
    unsigned char patternWidth;
    unsigned char patternHeight;
    char pad7a[0x12];
    unsigned short patternFirstTile;
};

enum {
    kDisplayModeNoPattern = 3, // MapDisplay_LoadLocalMap: map type 0 zones
    kScreenTiles = 0x20,       // a BG screen is 32 x 32 tiles
};

#if defined(jpn)
typedef int TaskHandle02020fc4;
#else
typedef int* TaskHandle02020fc4;
#endif
// Main, originally func_02020fc4 (USA 0x02020fc4, EUR 0x02020fd4, JPN 0x02020bc8)
extern "C" ARM void MapDisplay_LoadBackgroundPattern(struct MapDisplayPattern_02020fc4* self, TaskHandle02020fc4 patternTask, SafeAllocator* allocator) {
    BackgroundLoader* loader = BackgroundLoader::GetInstance();
    int* bgTransfers = (int*)BgVram_GetInstance();

    if (self->displayMode == kDisplayModeNoPattern) {
        self->blankTile = 0;
    } else {
        void* fileData = 0;
        unsigned int fileLength = 0;
        loader->GetLoadedFileByID((IS_JPN ? (int)patternTask : *(int*)patternTask), &fileData, &fileLength);
        BgImage_Clear((struct State0xbb1c*)((char*)self + 0x78));
        BgImage_Load((struct Obj0203bb3c*)((char*)self + 0x78), (char*)fileData, allocator, 1, 1);

        int row;
        for (row = 0; row < kScreenTiles / self->patternHeight; row++) {
            int col;
            for (col = 0; col < kScreenTiles / self->patternWidth; col++) {
                BgImage_Place((struct Bcb8Params*)((char*)self + 0x78),
                                    col * self->patternWidth, row * self->patternHeight);
            }
        }

        // One empty tile after the pattern's (BgTransfers_LoadTiles hands tiles out in order); the map
        // screen is cleared to it (MapDisplay_DrawFreeScrollMap)
        int emptyTile[8];
        self->blankTile = self->patternWidth * self->patternHeight + self->patternFirstTile;
        memset(emptyTile, 0, 0x20);
        BgTransfers_LoadTiles(bgTransfers, 1, 0, (int)emptyTile, 0x20, 1);
    }

    BackgroundLoader::GetInstance()->RemoveTask(IS_JPN ? (int)patternTask : *(int*)patternTask);
#if !defined(jpn)
    *patternTask = -1;
#endif
}
