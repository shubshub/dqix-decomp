#include <globaldefs.h>

struct BackgroundGraphics;
extern "C" void Background_DrawScreen(struct BackgroundGraphics*, unsigned int, int, int, short, short, short, short, unsigned short);

extern "C" void Background_UploadMap(struct BackgroundGraphics*, void*);

// USA: func_ov000_02175480
extern "C" ARM void func_ov000_02175480(void* obj) {
    Background_DrawScreen((struct BackgroundGraphics*)((char*)obj + 0x8c4), 0, 0, 0, 0, 0, 0x20, 0x19, 0xffff);
    Background_UploadMap((struct BackgroundGraphics*)((char*)obj + 0x8c4), 0);
}
