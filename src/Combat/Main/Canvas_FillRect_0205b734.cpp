#include <globaldefs.h>

struct Struct_0205b1ac {
    int unknown_0_;
    short unknown_4_;
    short unknown_6_;
    short unknown_8_;
    short unknown_a_;
};
struct Struct_0205b734 {
    unsigned char* unknown_0_;
    Struct_0205b1ac* unknown_4_;
    unsigned char unknown_8_;
};
extern "C" Struct_0205b1ac* func_0205b1ac(Struct_0205b1ac*, unsigned int, int, int);

// Main, originally func_0205b734 (USA 0x0205b734, EUR 0x0205b744, JPN 0x0205ca98)
extern "C" ARM void Canvas_FillRect(TileCanvas0205b734* canvas, short x, short y, short endX, short endY, unsigned char color) {
    unsigned char* pixels = canvas->pixels;
    unsigned char count;
    unsigned char highColor;
    unsigned char lowColor;
    short columnX;
    short row;
    short column;
    Rect0205b1ac* rectangles;
    if (!pixels || !(rectangles = canvas->rectangles)) return;
    lowColor = color & 15;
    highColor = lowColor << 4;
    count = canvas->rectangleCount;
    short width = endX - x;
    short height = endY - y;
    for (row = 0; row < height; row++) {
        columnX = x;
        for (column = 0; column < width; columnX++, column++) {
            Rect0205b1ac* rectangle = FindRectContainingPoint0205b1ac(rectangles, count, columnX, y);
            if (rectangle) {
                unsigned char* tile = pixels + rectangle->offset;
                short localX = columnX - rectangle->x;
                short localY = y - rectangle->y;
                tile += (((short)(localY >> 3) * (short)(rectangle->width >> 3) + (localX >> 3)) << 5);
                short pixelY = localY & 7;
                short pixelX = localX & 7;
                int pixelOffset = (pixelY << 2) + (pixelX >> 1);
                if (localX & 1) {
                    tile[pixelOffset] &= 15;
                    tile[pixelOffset] |= highColor;
                } else {
                    var11[var16] &= 0xf0;
                    var11[var16] |= var3;
                }
            }
        }
        arg2++;
    }
}
