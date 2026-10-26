#include <globaldefs.h>

// The window frame's state: closed, opening (WindowFrame_Open), open, closing (SetupField440Type3).
enum WindowFrameState {
    WindowFrameState_Closed = 0,
    WindowFrameState_Opening = 1,
    WindowFrameState_Open = 2,
    WindowFrameState_Closing = 3
};

// The window frame's rect (window frame +0x440): position, size, state, scale (fx32) and colour.
struct WindowFrameRect { short x, y, width, height; int state; char unknownC[4]; int scaleX; int scaleY; };

enum { kCloseStep = 0x199 }; // the height scale lost per frame while closing: 0.1, so a close takes 10 frames

// Main, originally UpdateTimedState0202f380 (USA 0x0202f380, EUR 0x0202f390, JPN 0x0202eef0)
ARM void WindowFrame_Update(void* frame, int frames) {
    WindowFrameRect* rect = *(WindowFrameRect**)((char*)frame + 0x440);
    if (frames == 0) frames = 1;
    if (rect == 0) return;
    switch (rect->state) {
    case WindowFrameState_Opening:
        rect->state = WindowFrameState_Open;
        (*(WindowFrameRect**)((char*)frame + 0x440))->scaleY = 0x1000;
        break;
    case WindowFrameState_Closing:
        rect->scaleY -= frames * kCloseStep;
        if ((*(WindowFrameRect**)((char*)frame + 0x440))->scaleY <= 0) {
            (*(WindowFrameRect**)((char*)frame + 0x440))->state = WindowFrameState_Closed;
            (*(WindowFrameRect**)((char*)frame + 0x440))->scaleY = 0;
        }
        break;
    case WindowFrameState_Closed:
    case WindowFrameState_Open:
    default:
        return;
    }
}
