#include <globaldefs.h>

extern "C" void func_02047b40(void* a, int b, int d);

// Main, originally Forward02047b30 (USA 0x02047b30, EUR 0x02047b40, JPN 0x02048950)
ARM void SprSprite_LoadFile(void* a, int b, int c, int d) {
    func_02047b40(a, b, d);
}
