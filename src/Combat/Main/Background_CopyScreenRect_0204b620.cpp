#include <globaldefs.h>

struct Struct_0204b620 {
    short unknown_0_;
    short unknown_2_;
    char unknown_4_[8];
    unsigned short* unknown_c_;
};

// Main, originally func_0204b620 (USA 0x0204b620, EUR 0x0204b630, JPN 0x0204c440)
extern "C" ARM void Background_CopyScreenRect(void* unused, unsigned short* destination, TileSource0204b620* source,
    short sourceX, short sourceY, short destX, short destY, short width, short height, unsigned short palette) {
    if (!destination || !source) return;
    if (destX >= 32 || destY >= 25) return;
    if (destX + width <= 0 || destY + height <= 0) return;
    if (width <= 0 || height <= 0) return;
    short sourceWidth = source->width;
    short sourceHeight = source->height;
    if (sourceWidth <= sourceX || sourceHeight <= sourceY || sourceX + width <= 0 || sourceY + height <= 0) return;
    if (sourceX < 0) {
        destX = (short)(destX - sourceX);
        width = (short)(width + sourceX);
        sourceX = 0;
    } else if (sourceWidth < sourceX + width) width = (short)(sourceWidth - sourceX);
    if (sourceY < 0) {
        destY = (short)(destY - sourceY);
        height += sourceY;
        sourceY = 0;
    } else if (sourceHeight < sourceY + height) height = (short)(sourceHeight - sourceY);
    if (sourceWidth < width) width = sourceWidth;
    if (sourceHeight < height) height = sourceHeight;
    if (destX < 0) {
        sourceX = (short)(sourceX - destX);
        width = (short)(width + destX);
        destX = 0;
    } else if (destX + width > 32) width = (short)(32 - destX);
    if (destY < 0) {
        sourceY = (short)(sourceY - destY);
        height = (short)(height + destY);
        destY = 0;
    } else if (destY + height > 25) height = (short)(25 - destY);
    unsigned short* input = source->tiles;
    if (!input) return;
    input += sourceWidth * sourceY + sourceX;
    unsigned short* output = destination + destY * 32 + destX;
    if (palette != 0xffff) {
        for (unsigned short row = 0; row < height; row++) {
            for (unsigned short column = 0; column < width; column++) {
                output[column] = input[column] & 0xfff;
                output[column] |= (unsigned short)(palette << 12);
            }
            var2 += var0;
            var3 += 32;
        }
    } else {
        for (unsigned short var6 = 0; var6 < arg8; var6++) {
            for (unsigned short var7 = 0; var7 < arg7; var7++) var3[var7] = var2[var7];
            var2 += var0;
            var3 += 32;
        }
    }
}
