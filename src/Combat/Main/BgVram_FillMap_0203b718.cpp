#include <globaldefs.h>
#include "std_library_functions.h"

extern char data_021065d8[];
extern char data_02105fd8[];

// data_02105254: per screen (0 main, 1 sub) the byte offset of the next free BG character data and the tile count
// (BgTransfers_LoadTiles adds to both and returns the first tile), and a dirty flag per screen and BG for the
// map buffers (data_021065d8 BG0, data_02105fd8 BG1) that BgTransfers_UploadDirtyScreens uploads to the sub screen.
struct BgVram {
    int charOffset[8];
    int tileCount[8];
    int mapDirty[2][4];
};

// Main, originally SetArraySlotFlag0203b718 (USA 0x0203b718, EUR 0x0203b728, JPN 0x0203b170)
ARM void BgVram_FillMap(void* bgVramRaw, int screen, int bg, int fillByte) {
    BgVram* bgVram = (BgVram*)bgVramRaw;
    switch (screen) {
    case 0:
    case 1:
        switch (bg) {
        case 0:
            memset(data_021065d8, fillByte, 0x1000);
            break;
        case 1:
            memset(data_02105fd8, fillByte, 0x600);
            break;
        }
        break;
    }
    (&bgVram->mapDirty[0][0])[bg + screen * 4] = 1;
}
