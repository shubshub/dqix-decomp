#include <globaldefs.h>
#include "std_library_functions.h"
#include "NitroSDK/Graphics.h"

extern "C" void SprSprite_DrawGroup(void* sprite, int group, int param1, int color);

// Each piece's base scale (fx32): 1.0, except 0 on the axis an edge piece stretches along (pieces 1/5 along x,
// 3/7 along y), which WindowFrame_DrawBox fills in.
struct PieceScales {
    int scale[8][2];
};
extern struct PieceScales data_020e73fc;

// The window frame's rect: +0x18 its colour, copied into each piece.
struct WindowFrameRect {
    char unknown0[0x18];
    unsigned short color;
};

enum {
    kMinimumSize = 0x8000,          // 8.0: a smaller frame isn't drawn
    kBackgroundInset = 0x3000,      // the background quad starts 3.0 inside the frame on each side
    kFrameDepth = 0x400000,         // z of the background and the pieces
    kNoTexture = 0x20030000,        // TEXIMAGE_PARAM with no texture format
    kBackgroundPolygon = 0x3b1200c0 // POLYGON_ATTR: polygon id 59, alpha 18 of 31, front and back faces
};

// Draws a window frame at (x, y) of width x height (fx32 pixels): a translucent black background quad, then, if
// drawPieces, its eight .spr pieces (corners 0/2/4/6 clockwise from the top left, edges 1/3/5/7 between them).
// Main, originally func_0202f45c (USA 0x0202f45c, EUR 0x0202f46c, JPN 0x0202efcc)
extern "C" ARM void WindowFrame_DrawBox(void* frame, int x, int y, int width, int height, int drawPieces) {
    if (width < kMinimumSize || height < kMinimumSize) return;

    GXFIFO_TEXIMAGE_PARAMS = kNoTexture;
    GXFIFO_POLYGON_ATTRIBUTES = kBackgroundPolygon;
    GXFIFO_MATRIX_PUSH = 0;
    GXFIFO_MATRIX_TRANSLATE = x + kBackgroundInset;
    GXFIFO_MATRIX_TRANSLATE = y + kBackgroundInset;
    GXFIFO_MATRIX_TRANSLATE = kFrameDepth;
    GXFIFO_MATRIX_SCALE = width - 2 * kBackgroundInset;
    GXFIFO_MATRIX_SCALE = height - 2 * kBackgroundInset;
    GXFIFO_MATRIX_SCALE = 0x1000;
    GXFIFO_POLYGON_BEGIN = 1;
    GXFIFO_VERTEX_COLOR = 0;
    GXFIFO_VERTEX_16 = 0;
    GXFIFO_VERTEX_16 = 0;
    GXFIFO_VERTEX_16 = 0x1000;
    GXFIFO_VERTEX_16 = 0;
    GXFIFO_VERTEX_16 = 0x10001000;
    GXFIFO_VERTEX_16 = 0;
    GXFIFO_VERTEX_16 = 0x10000000;
    GXFIFO_VERTEX_16 = 0;
    GXFIFO_POLYGON_END = 0;
    GXFIFO_MATRIX_POP = 1;

    if (drawPieces == 0) return;

    int edgeScaleX = (int)((width - kMinimumSize) / 6.0f);
    int edgeScaleY = (int)((height - kMinimumSize) / 6.0f);

    int positions[8][2];
    positions[0][0] = x - 0x1000;
    positions[0][1] = y - 0x1000;
    positions[1][0] = (x + 0x3000) - (edgeScaleX & ~0xfff);
    positions[1][1] = y - 0x1000;
    positions[2][0] = (x + width) - 0x7000;
    positions[2][1] = y - 0x1000;
    positions[3][0] = (x + width) - 0x7000;
    positions[3][1] = (y + 0x3000) - (edgeScaleY & ~0xfff);
    positions[4][0] = (x + width) - 0x7000;
    positions[4][1] = (y + height) - 0x7000;
    positions[5][0] = (x + 0x3000) - (edgeScaleX & ~0xfff);
    positions[5][1] = (y + height) - 0x7000;
    positions[6][0] = x - 0x1000;
    positions[6][1] = (y + height) - 0x7000;
    positions[7][0] = x - 0x1000;
    positions[7][1] = (y + 0x3000) - (edgeScaleY & ~0xfff);

    struct PieceScales scales = data_020e73fc;
    scales.scale[1][0] = edgeScaleX;
    scales.scale[5][0] = edgeScaleX;
    scales.scale[3][1] = edgeScaleY;
    scales.scale[7][1] = edgeScaleY;

    unsigned char* piece = (unsigned char*)frame;
    for (int i = 0; i < 8; ++i) {
        int* position = positions[i];
        int* scale = scales.scale[i];
        GXFIFO_MATRIX_PUSH = 0;
        int pieceY = position[1];
        GXFIFO_MATRIX_TRANSLATE = position[0];
        GXFIFO_MATRIX_TRANSLATE = pieceY;
        GXFIFO_MATRIX_TRANSLATE = kFrameDepth;
        int scaleY = scale[1];
        GXFIFO_MATRIX_SCALE = scale[0];
        GXFIFO_MATRIX_SCALE = scaleY;
        GXFIFO_MATRIX_SCALE = 0x1000;
        WindowFrameRect* rect = *(WindowFrameRect**)((char*)frame + 0x440);
        unsigned short color = rect->color;
        *(unsigned short*)(piece + 0x80) = color; // Foo02048004::color
        SprSprite_DrawGroup(piece, 0, 1, color);
        GXFIFO_MATRIX_POP = 1;
        piece += 0x88; // sizeof(Foo02048004)
    }
}
