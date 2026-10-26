#include <globaldefs.h>

struct Struct_0205bd20;
struct Struct_0205d81c;
struct Elem_0205d81c;

extern "C" int TouchGrid_IsSelectionTapped(struct Struct_0205bd20* s, int key);
extern "C" struct Elem_0205d81c* func_0205d81c(struct Struct_0205d81c* s, int key);
extern "C" int WindowPane_IsReady(unsigned char* obj);

// A window: the header's CreationWindow, up to activeWindow.
struct Obj_0205da38 {
    unsigned char unknown[4];
    int frame[20];
    int cursor[16];
    unsigned char unknown94[4];
    void* layers;
    void* panes;
    short layout[8];
    unsigned char activeWindow;
};

// Main, originally IsActiveElementFlag2Set0205da38 (USA 0x0205da38, EUR 0x0205da48, JPN 0x0205ed4c)
extern "C" ARM int Window_IsSelectionTouched(struct Obj_0205da38* window, int key) {
    unsigned char* pane;
    if (TouchGrid_IsSelectionTapped((struct Struct_0205bd20*)window->frame, key) == 0) goto ret0;
    pane = (unsigned char*)func_0205d81c((struct Struct_0205d81c*)window, window->activeWindow);
    if (pane == NULL) goto ret0;
    if (WindowPane_IsReady(pane) == 0) goto ret0;
    if (pane[0xc5] & 2) return 1;
ret0:
    return 0;
}
