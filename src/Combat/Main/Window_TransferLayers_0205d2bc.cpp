#include <globaldefs.h>
#include "Graphics/Background.h"


// The header's CreationWindow, up to layerCount.
struct Obj0205d2bc {
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

extern "C" void Background_TransferMap(BackgroundGraphics*, int);

// Main, originally InitEntries0205d2bc (USA 0x0205d2bc, EUR 0x0205d2cc, JPN 0x0205e5ec)
ARM void Window_TransferLayers(struct Obj0205d2bc* window) {
    unsigned char i;
    if (window->layers == 0) return;
    for (i = 0; i < window->layerCount; i++) {
        Background_TransferMap(&window->layers[i], 0);
    }
}
