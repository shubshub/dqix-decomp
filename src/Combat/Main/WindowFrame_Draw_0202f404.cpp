#include <globaldefs.h>

extern "C" void WindowFrame_DrawBox(void* frame, int x, int y, int width, int height, int drawPieces, int unused);

// The window frame's rect (window frame +0x440): position, size, state, scale (fx32) and colour.
struct WindowFrameRect {
    short x;
    short y;
    short width;
    short height;
    int   state;
    int   unknownC;
    int   scaleX;
    int   scaleY;
};

// Draws the frame unless it is closed (state 0), at its size times its scale. WindowFrame_DrawBox doesn't read the
// last argument.
// Main, originally EmitScaledField0x440_0202f404 (USA 0x0202f404, EUR 0x0202f414, JPN 0x0202ef74)
ARM void WindowFrame_Draw(void* frame, int drawPieces, int unused) {
    struct WindowFrameRect* rect = *(struct WindowFrameRect**)((char*)frame + 0x440);
    if (rect != NULL && rect->state != 0) {
        WindowFrame_DrawBox(frame, rect->x << 12, rect->y << 12,
                      rect->width * rect->scaleX, rect->height * rect->scaleY, drawPieces, unused);
    }
}
