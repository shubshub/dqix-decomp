#include <globaldefs.h>
#include "NitroSDK/Cache.h"

// A screen block holds 32 x 32 map entries
enum { kBlockWidth = 32, kBlockEntries = 32 * 32 };

// Main, originally func_0203b97c (USA 0x0203b97c, EUR 0x0203b98c, JPN 0x0203b3d4)
extern "C" ARM void BgTransfers_WriteScreenBuffer(void* bgTransfers, unsigned short* destination, int width, int height, int startX, int startY, const unsigned short* source, unsigned int copyWidth, unsigned int copyHeight, unsigned short firstTile) {
    int blockRow;
    unsigned int blockColumns;
    int y;
    if (width <= startX || height <= startY) return;
    blockColumns = (unsigned int)width >> 5;
    for (unsigned int row = 0; row < copyHeight; row++) {
        y = startY + row;
        for (unsigned int column = 0; column < copyWidth; column++) {
            blockRow = (y / 32) * blockColumns;
            int x = startX + column;
            if (x >= 0 && y >= 0 && width > x && height > y) {
                int block = blockRow + x / 32;
                unsigned int offset = x + (y << 5) + block * (kBlockEntries - kBlockWidth);
                unsigned short value = source[column + row * copyWidth];
                destination[offset] = value;
                destination[offset] += firstTile;
            }
        }
    }
    CleanInvalidateCacheRange(arg1, arg3 * (arg2 << 1));
}
