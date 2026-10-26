#include <globaldefs.h>

#if defined(jpn)
#define func_0205b008 func_0205c3a4
#endif

extern "C" int func_0205b008(int a, void* b, int c, int d, int e, int f);

// Main, originally SetBitfield0205afb0 (USA 0x0205afb0, EUR 0x0205afc0, JPN 0x0205c34c)
ARM void SpriteContext_SetSpritePalette(int a, void* b, int c) {
    func_0205b008(a, b, 2, 0xf000, 0xc, (unsigned short)(c & 0xf));
}
