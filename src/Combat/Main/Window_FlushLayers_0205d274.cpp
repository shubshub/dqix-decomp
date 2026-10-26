#include <globaldefs.h>
#include "Graphics/Background.h"

extern "C" void Background_FlushMap(void* p, int flag);


// The header's CreationWindow, up to layerCount.
struct Cont0205d274 {
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

// Main, originally CallFunc0204b04cOverList0x98 (USA 0x0205d274, EUR 0x0205d284, JPN 0x0205e5a4)
extern "C" ARM void Window_FlushLayers(Cont0205d274* window) {
    unsigned char i;
    if (window->layers == NULL) return;
    for (i = 0; i < window->layerCount; i++) {
        Background_FlushMap(&window->layers[i], 0);
    }
}
