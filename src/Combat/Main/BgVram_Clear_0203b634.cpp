#include <globaldefs.h>
#include "std_library_functions.h"

// data_02105254: per screen (0 main, 1 sub) the byte offset of the next free BG character data and the tile count
// (BgTransfers_LoadTiles adds to both and returns the first tile), and a dirty flag per screen and BG for the
// map buffers (data_021065d8 BG0, data_02105fd8 BG1) that BgTransfers_UploadDirtyScreens uploads to the sub screen.
struct BgVram {
    int charOffset[8];
    int tileCount[8];
    int mapDirty[2][4];
};

// Main, originally ClearThreeRegions0203b634 (USA 0x0203b634, EUR 0x0203b644, JPN 0x0203b08c)
ARM void BgVram_Clear(char* bgVramRaw) {
    BgVram* bgVram = (BgVram*)bgVramRaw;
    memset(bgVram->charOffset, 0, sizeof(bgVram->charOffset));
    memset(bgVram->tileCount, 0, sizeof(bgVram->tileCount));
    memset(bgVram->mapDirty, 0, sizeof(bgVram->mapDirty));
}
