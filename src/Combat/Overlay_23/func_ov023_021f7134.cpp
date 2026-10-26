#include <globaldefs.h>

extern "C" void SprSprite_DrawGroup(void*, int, int);

// USA: func_ov023_021f7134
extern "C" ARM void func_ov023_021f7134(char* obj) {
    if (*(unsigned char*)(obj + 0xc) & 8) return;
    SprSprite_DrawGroup(obj + 0x20, 0, 1);
}
