#include <globaldefs.h>

extern "C" void SprSprite_Init(void* obj);

// USA: func_0202f1a4
ARM void InitEightSubStructs_0202f1a4(char* obj) {
    int i;
    for (i = 0; i < 8; i++) {
        SprSprite_Init(obj + i * 0x88);
    }
    *(int*)(obj + 0x440) = 0;
    *(int*)(obj + 0x444) = 0;
}
