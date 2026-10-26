#include <globaldefs.h>

// A BG tile image (BgImage_Load's Obj0203bb3c): the 8-byte header stays, the fields the load fills are cleared
struct State0xbb1c {
    char header[8];
    int map;           // the screen map copy BgImage_Load allocates
    int unknownC;
    int unknown10;
    short firstTile;   // the first tile index BgTransfers_LoadTiles returned
    short screen;      // 0 main, 1 sub
    short bg;          // BG 0-3
};

// Main, originally ClearFields0x8_0203bb1c (USA 0x0203bb1c, EUR 0x0203bb2c, JPN 0x0203b574)
extern "C" ARM void BgImage_Clear(struct State0xbb1c* image) {
    image->map = 0;
    image->unknownC = 0;
    image->unknown10 = 0;
    image->firstTile = 0;
    image->screen = 0;
    image->bg = 0;
}
