#include <globaldefs.h>

extern "C" void SprSprite_Parse(void* a, int b, int d);

// Main, originally Forward02047b30 (USA 0x02047b30, EUR 0x02047b40, JPN 0x02048950)
ARM void SprSprite_LoadFile(void* a, int b, int c, int d) {
    SprSprite_Parse(a, b, d);
}
