#include <globaldefs.h>
#include "std_library_functions.h"

extern "C" int LoadToSubBG0CharacterData(int arg0, int arg1, unsigned int arg2);
extern "C" int LoadToSubBG1CharacterData(int arg0, int arg1, unsigned int arg2);
extern int data_021065d8;
extern int data_02105fd8;

// data_02105254: per screen (0 main, 1 sub) the byte offset of the next free BG character data and the tile count
// (BgTransfers_LoadTiles adds to both and returns the first tile), and a dirty flag per screen and BG for the
// map buffers (data_021065d8 BG0, data_02105fd8 BG1) that BgTransfers_UploadDirtyScreens uploads to the sub screen.
struct BgVram {
    int charOffset[8];
    int tileCount[8];
    int mapDirty[2][4];
};

enum { kTileBytes = 0x20 };     // one 16-colour 8x8 tile

// Main, originally SetupBankModeAndTransfer_0203b678 (USA 0x0203b678, EUR 0x0203b688, JPN 0x0203b0d0)
ARM void BgVram_ResetWithBlankTile(int* bgVramWords, int screen, int bg) {
    BgVram* bgVram = (BgVram*)bgVramWords;
    char blankTile[kTileBytes];
    bgVram->charOffset[screen] = kTileBytes;
    bgVram->tileCount[screen] = 1;
    memset(blankTile, 0, sizeof(blankTile));
    if (screen == 1) {
        switch (bg) {
        case 0:
            memset(&data_021065d8, 0, 0x1000);
            LoadToSubBG0CharacterData((int)blankTile, 0, kTileBytes);
            break;
        case 1:
            memset(&data_02105fd8, 0, 0x600);
            LoadToSubBG1CharacterData((int)blankTile, 0, kTileBytes);
            break;
        }
    }
}
