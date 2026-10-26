#include <globaldefs.h>

struct Rect0205b1ac {
    int offset;
    short x;
    short y;
    short width;
    short height;
};
struct TileCanvas0205b734 {
    unsigned char* pixels;
    Rect0205b1ac* rectangles;
    unsigned char rectangleCount;
};
extern "C" Rect0205b1ac* func_0205b1ac(Rect0205b1ac*, unsigned int, int, int);

// Main, originally func_0205b734 (USA 0x0205b734, EUR 0x0205b744, JPN 0x0205ca98)
extern "C" ARM void Canvas_FillRect(TileCanvas0205b734* canvas, short x, short y, short endX, short endY, unsigned char color) {
    unsigned char* pixels = canvas->pixels;
    unsigned char count;
    unsigned char var2;
    unsigned char var3;
    short var4;
    short row;
    short column;
    Rect0205b1ac* rectangles;
    if (!pixels || !(rectangles = canvas->rectangles)) return;
    var3 = color & 15;
    var2 = var3 << 4;
    count = canvas->rectangleCount;
    short width = endX - x;
    short height = endY - y;
    for (row = 0; row < height; row++) {
        var4 = x;
        for (column = 0; column < width; var4++, column++) {
            Rect0205b1ac* var10 = func_0205b1ac(rectangles, count, var4, y);
            if (var10) {
                unsigned char* tile = pixels + var10->offset;
                short var12 = var4 - var10->x;
                short var13 = y - var10->y;
                tile += (((short)(var13 >> 3) * (short)(var10->width >> 3) + (var12 >> 3)) << 5);
                short pixelY = var13 & 7;
                short pixelX = var12 & 7;
                int pixelOffset = (pixelY << 2) + (pixelX >> 1);
                if (var12 & 1) {
                    tile[pixelOffset] &= 15;
                    tile[pixelOffset] |= var2;
                } else {
                    tile[pixelOffset] &= 0xf0;
                    tile[pixelOffset] |= var3;
                }
            }
        }
        y++;
    }
}
