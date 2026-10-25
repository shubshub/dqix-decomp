#include <globaldefs.h>
#include "Combat/MapDisplay.h"

struct InitTarget0205cfd4;
extern void Window_Init(struct InitTarget0205cfd4* s);

extern void Background_Init(struct BackgroundGraphics* obj);

extern "C" void WindowPane_Init(void*);

#if defined(jpn)
static const int kLayoutShift=0x220;
#else
static const int kLayoutShift=0;
#endif

// USA: func_ov017_021a5b48
ARM void InitFieldArenaLists_021a5b48(unsigned char* base) {
    Window_Init(*(struct InitTarget0205cfd4**)(base + 0x4090 - kLayoutShift));
    for (int i = 0; i < 2; i++) {
        Background_Init((struct BackgroundGraphics*)(base + 0x4094 - kLayoutShift + i * 0x20));
    }
    WindowPane_Init(base + 0x40d4 - kLayoutShift);
    *(int*)(base + 0x41b8 - kLayoutShift) = 0;
    *(int*)(base + 0x41bc - kLayoutShift) = -1;
    *(int*)(base + 0x41b4 - kLayoutShift) = 0;
    *(int*)(base + 0x41c0 - kLayoutShift) = 0;
}
