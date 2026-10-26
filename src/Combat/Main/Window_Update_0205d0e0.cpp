#include <globaldefs.h>
#include "Graphics/Window.h"

// The header's CreationWindow, up to pendingClose (read here as a byte).
struct Struct_0205d81c {
    unsigned char unknown[4];
    int frame[20];
    int cursor[16];
    unsigned char unknown94[4];
    int layers;
    struct WindowPane* panes;
    short layout[8];
    unsigned char activeWindow;
    unsigned char nextWindow;
    unsigned char layerCount;
    unsigned char paneCount;
    unsigned char count;
    unsigned char flags;
    unsigned char noHorizontalInset;
    unsigned char fontHeight;
    unsigned char pendingClose;
};

struct Struct0205d888;
extern "C" void* Window_GetTopPane(struct Struct0205d888* p);

extern "C" int Window_HandleInput(void* selfPtr, int p1);
extern "C" unsigned int Window_GetPage(unsigned char* obj);
extern "C" void WindowPane_SetIndicatorPage(unsigned char* obj, unsigned char value);
extern "C" unsigned int Window_GetPageCount(unsigned char* obj);
extern "C" void WindowPane_SetIndicatorPageCount(unsigned char* obj, int val);
extern "C" void WindowPane_Update(void* entry, int arg);
extern "C" struct WindowPane* func_0205d81c(struct Struct_0205d81c* s, int key);
struct Obj0204ffc0;
extern "C" void func_0204ffc0(struct Obj0204ffc0* a, int b);

// Main, originally func_0205d0e0 (USA 0x0205d0e0, EUR 0x0205d0f0, JPN 0x0205e410)
extern "C" ARM int Window_Update(void* windowPtr, int ticks) {
    struct Struct_0205d81c* window = (struct Struct_0205d81c*)windowPtr;
    int input;
    struct WindowPane* pane;
    unsigned char i;

    if (window->layers == 0) return 0;
    if (window->panes == 0) return 0;

    input = 0;
    pane = (struct WindowPane*)Window_GetTopPane((struct Struct0205d888*)windowPtr);
    if (pane != 0) {
        input = Window_HandleInput(windowPtr, ticks);
        if (window->activeWindow == pane->id_) {
            if (pane->indicatorEnabled_) {
                WindowPane_SetIndicatorPage((unsigned char*)pane, Window_GetPage((unsigned char*)windowPtr));
                WindowPane_SetIndicatorPageCount((unsigned char*)pane, (unsigned char)Window_GetPageCount((unsigned char*)windowPtr));
            }
        }
    }

    for (i = 0; i < window->paneCount; i++) {
        WindowPane_Update((void*)&window->panes[i], ticks);
    }

    if (window->pendingClose != 0xff) {
        pane = func_0205d81c(window, window->pendingClose);
        if (pane != 0) {
            func_0204ffc0((struct Obj0204ffc0*)pane, -1);
        }
        window->pendingClose = 0xff;
    }

    return input;
}
