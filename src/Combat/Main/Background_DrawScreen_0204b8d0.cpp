#include <globaldefs.h>
#include "Graphics/Background.h"

extern "C" void Background_CopyScreenRect(void*, void*, BackgroundScreen*, int, int, int, int, int, int, int);

// Main, originally DispatchEntry0204b8d0 (USA 0x0204b8d0, EUR 0x0204b8e0, JPN 0x0204c6f0)
ARM void Background_DrawScreen(struct BackgroundGraphics* layer, unsigned int index, int sourceX, int sourceY,
                              short destX, short destY, short width, short height, unsigned short palette) {
    if (layer->screenCount_ <= index) return;
    BackgroundScreen* screen = layer->screens_;
    if (screen == 0) return;
    screen += index;
    void* map = layer->map_;
    if (map == NULL) return;
    Background_CopyScreenRect(layer, map, screen, sourceX, sourceY, destX, destY, width, height, palette);
}
