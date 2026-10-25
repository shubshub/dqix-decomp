#include <globaldefs.h>
#include "Graphics/Background.h"

void Background_ClearMap(BackgroundGraphics*, void*);

// The header's CreationWindow, up to layerCount.
struct Cont0205d1e0 {
    unsigned char unknown[4];
    int frame[20];
    int cursor[16];
    unsigned char unknown94[4];
    BackgroundGraphics* layers;
    void* panes;
    short layout[8];
    unsigned char activeWindow;
    unsigned char nextWindow;
    unsigned char layerCount;
};

// Main, originally ClearBuffers0204b010OverList0x98 (USA 0x0205d1e0, EUR 0x0205d1f0, JPN 0x0205e510)
ARM void Window_ClearLayers(Cont0205d1e0* window) {
    unsigned char i;
    if (window->layers == NULL) return;
    for (i = 0; i < window->layerCount; i++) {
        Background_ClearMap(&window->layers[i], NULL);
    }
}
