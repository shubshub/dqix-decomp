#include <globaldefs.h>

#if defined(jpn)
#define func_0205b008 func_0205c3a4
#endif

extern "C" int func_0205b008(int a, void* b, int c, int d, int e, int f);

// Main, originally SetBitfield0205afdc (USA 0x0205afdc, EUR 0x0205afec, JPN 0x0205c378)
extern "C" ARM void SpriteContext_SetSpriteObjMode(int a, void* b, int c) {
    func_0205b008(a, b, 0, 0xc00, 0xa, (unsigned short)(c & 0x3));
}
