#include <globaldefs.h>

extern char data_02105254;

// A BG tile image (BgImage_Load's Obj0203bb3c)
struct Bcb8Params {
    unsigned char width;
    unsigned char height;
    unsigned char pad2[6];
    unsigned int map;
    unsigned char padC[8];
    unsigned short firstTile;
    unsigned short screen;
    unsigned short bg;
};

extern "C" void BgTransfers_PlaceMap(void* bgTransfers, int screen, int bg, int x, int y,
                              unsigned int map, int mapWidth, int mapHeight, int firstTile);

// Main, originally ForwardParamsToB8bc_0203bcb8 (USA 0x0203bcb8, EUR 0x0203bcc8, JPN 0x0203b710)
ARM void BgImage_Place(struct Bcb8Params* image, int x, int y) {
    BgTransfers_PlaceMap(&data_02105254, image->screen, image->bg, x, y,
                  image->map, image->width, image->height, image->firstTile);
}
