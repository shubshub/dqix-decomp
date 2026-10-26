#include <globaldefs.h>

struct Struct_020c5588 {
    volatile unsigned int color;
    volatile unsigned short depth;
};

// Main, originally Set3DClearColor_020c5588 (USA 0x020c5588, EUR 0x020c5598, JPN 0x020c7054)
extern "C" ARM void Set3DClearColor(int color, int alpha, int depth, int polygonId, int fogEnable) {
    struct Struct_020c5588* reg = (struct Struct_020c5588*)0x4000350;
    unsigned int value = color | (alpha << 16) | (polygonId << 24);
    if (fogEnable) value |= 0x8000;
    reg->color = value;
    reg->depth = depth;
}
