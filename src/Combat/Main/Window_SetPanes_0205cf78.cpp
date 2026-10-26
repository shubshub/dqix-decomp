#include <globaldefs.h>
#include "Graphics/Window.h"

// The header's CreationWindow, up to paneCount.
struct Struct_0205cf78 {
    unsigned char unknown[4];
    int frame[20];
    int cursor[16];
    unsigned char unknown94[4];
    void* layers;
    struct WindowPane* panes;
    short layout[8];
    unsigned char activeWindow;
    unsigned char nextWindow;
    unsigned char layerCount;
    unsigned char paneCount;
};

// Main, originally LinkArrayPrevPointers0205cf78 (USA 0x0205cf78, EUR 0x0205cf88, JPN 0x0205e2a8)
extern "C" ARM void Window_SetPanes(struct Struct_0205cf78* window, struct WindowPane* panes, unsigned char count) {
    unsigned char i;
    window->panes = panes;
    window->paneCount = count;
    if (window->panes == 0 || window->paneCount == 0) return;
    for (i = 1; i < window->paneCount; i++) {
        window->panes[i].previous_ = &window->panes[i - 1];
    }
}
