#include <globaldefs.h>

struct BackgroundGraphics;
void Background_DrawScreen(struct BackgroundGraphics*, unsigned int, int, int, short, short, short, short, unsigned short);

void Background_UploadMap(struct BackgroundGraphics*, void*);

// USA: func_ov000_02175480
ARM void DispatchAndFlush02175480(void* obj) {
    Background_DrawScreen((struct BackgroundGraphics*)((char*)obj + 0x8c4), 0, 0, 0, 0, 0, 0x20, 0x19, 0xffff);
    Background_UploadMap((struct BackgroundGraphics*)((char*)obj + 0x8c4), 0);
}
