#include <globaldefs.h>
#include "Graphics/Background.h"

// Main, originally func_0204b620 (USA 0x0204b620, EUR 0x0204b630, JPN 0x0204c440)
extern "C" ARM void Background_CopyScreenRect(void* unused, unsigned short* destination, BackgroundScreen* source,
    short sourceX, short sourceY, short destX, short destY, short width, short height, unsigned short palette) {
    if (!destination || !source) return;
    if (destX >= BackgroundMap_Columns || destY >= BackgroundMap_Rows) return;
    if (destX + width <= 0 || destY + height <= 0) return;
    if (width <= 0 || height <= 0) return;
    short sourceWidth = source->width_;
    short sourceHeight = source->height_;
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
    } else if (destX + width > BackgroundMap_Columns) width = (short)(BackgroundMap_Columns - destX);
    if (destY < 0) {
        sourceY = (short)(sourceY - destY);
        height = (short)(height + destY);
        destY = 0;
    } else if (destY + height > BackgroundMap_Rows) height = (short)(BackgroundMap_Rows - destY);
    unsigned short* input = source->tiles_;
    if (!input) return;
    input += sourceWidth * sourceY + sourceX;
    unsigned short* output = destination + destY * BackgroundMap_Columns + destX;
    if (palette != BackgroundPalette_Keep) {
        for (unsigned short row = 0; row < height; row++) {
            for (unsigned short column = 0; column < width; column++) {
                output[column] = input[column] & 0xfff;
                output[column] |= (unsigned short)(palette << 12);
            }
            input += sourceWidth;
            output += BackgroundMap_Columns;
        }
    } else {
        for (unsigned short row = 0; row < height; row++) {
            for (unsigned short column = 0; column < width; column++) output[column] = input[column];
            input += sourceWidth;
            output += BackgroundMap_Columns;
        }
    }
}
