#include <globaldefs.h>

extern "C" void BgTransfers_WriteScreenBuffer(void* bgTransfers, void* screenBuffer, int bufferWidth, int bufferHeight, int startX, int startY, int map, int mapWidth, int mapHeight, unsigned short firstTile);

// The sub screen's BG0 and BG1 screen buffers (0x1000 and 0x600 bytes), uploaded by BgTransfers_UploadDirtyScreens
extern int data_021065d8;
extern int data_02105fd8;

// Size in tiles of the two sub screen buffers
enum {
    kSubBg0Width = 0x40,
    kSubBg0Height = 0x20,
    kSubBg1Width = 0x20,
    kSubBg1Height = 0x18
};

// Main, originally func_0203b8bc (USA 0x0203b8bc, EUR 0x0203b8cc, JPN 0x0203b314)
extern "C" ARM void BgTransfers_PlaceMap(void* bgTransfers, int screen, int bg, int x, int y, int map, int mapWidth, int mapHeight, unsigned short firstTile) {
    int* screenSlot = (int*)bgTransfers + (bg + screen * 4);
    screenSlot[0x10] = 1;
    if (screen == 1) {
        switch (bg) {
        case 0:
            BgTransfers_WriteScreenBuffer(bgTransfers, &data_021065d8, kSubBg0Width, kSubBg0Height, x, y, map, mapWidth, mapHeight, firstTile);
            break;
        case 1:
            BgTransfers_WriteScreenBuffer(bgTransfers, &data_02105fd8, kSubBg1Width, kSubBg1Height, x, y, map, mapWidth, mapHeight, firstTile);
            break;
        }
    }
}
