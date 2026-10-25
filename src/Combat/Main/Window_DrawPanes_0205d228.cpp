#include <globaldefs.h>
#include "Graphics/Window.h"
void WindowPane_Draw(struct Struct0204c8f0*);

// The header's CreationWindow, up to paneCount.
struct Cont0205d228 {
    unsigned char unknown[4];
    int frame[20];
    int cursor[16];
    unsigned char unknown94[4];
    void* layers;
    WindowPane* panes;
    short layout[8];
    unsigned char activeWindow;
    unsigned char nextWindow;
    unsigned char layerCount;
    unsigned char paneCount;
};

// Main, originally CallFunc0204c8f0OverList0x9c (USA 0x0205d228, EUR 0x0205d238, JPN 0x0205e558)
ARM void Window_DrawPanes(Cont0205d228* window) {
    unsigned char i;
    if (window->layers == NULL || window->panes == NULL) return;
    for (i = 0; i < window->paneCount; i++) {
        WindowPane_Draw((struct Struct0204c8f0*)(&window->panes[i]));
    }
}
