#include <globaldefs.h>

// The window frame's rect: +8 state, +0x10/+0x14 its x/y scale (fx32).
struct Field440Inner0202f6a4 {
    char unknown0[0x8];
    int state;
    int unknownC;
    int scaleX;
    int scaleY;
};

struct Field440Obj0202f6a4 {
    char pieces[0x440];
    struct Field440Inner0202f6a4* rect;
};

// Starts opening the frame: full width, zero height, state 1 (opening); WindowFrame_Update makes it
// state 2 (open) at full height on its next update.
// Main, originally SetupField440Type1 (USA 0x0202f6a4, EUR 0x0202f6b4, JPN 0x0202f214)
extern "C" ARM void WindowFrame_Open(struct Field440Obj0202f6a4* frame) {
    if (frame->rect == 0) {
        return;
    }
    frame->rect->scaleX = 0x1000;
    frame->rect->scaleY = 0;
    frame->rect->state = 1;
}
