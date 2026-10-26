#include <globaldefs.h>

struct Struct_ov003_02173b4c;
extern "C" void* func_ov003_02173bb0(Struct_ov003_02173b4c*, unsigned int);
extern "C" void SpriteContext_DrawSprite(void*, void*);
extern signed char data_ov003_0217fa14[];

// USA: func_ov003_02173bd8
extern "C" ARM void func_ov003_02173bd8(void* obj) {
    unsigned char* o = (unsigned char*)obj;
    unsigned int index;
    void* elem;
#if defined(jpn)
    enum { stateOffset = 0xe8, Enum_ov003_02173bd8_238 = 0xea, Enum_ov003_02173bd8_208 = 0xd0, entriesOffset = 0x13c, x = 0xa2000 };
#else
    enum { stateOffset = 0xec, Enum_ov003_02173bd8_238 = 0xee, Enum_ov003_02173bd8_212 = 0xd4, entriesOffset = 0x130, x = 0xb8000 };
#endif
    if (o[stateOffset] == 0) {
        return;
    }
    if (o[stateOffset] == 1) {
        if (o[Enum_ov003_02173bd8_238] < 2) {
            return;
        }
    }
#if defined(jpn)
    switch (o[Enum_ov003_02173bd8_208]) {
        case 0: elem = func_ov003_02173bb0((Struct_ov003_02173b4c*)((char*)obj + entriesOffset), 5); break;
        case 1: elem = func_ov003_02173bb0((Struct_ov003_02173b4c*)((char*)obj + entriesOffset), 4); break;
        case 2: elem = func_ov003_02173bb0((Struct_ov003_02173b4c*)((char*)obj + entriesOffset), 3); break;
        case 3: elem = func_ov003_02173bb0((Struct_ov003_02173b4c*)((char*)obj + entriesOffset), 2); break;
        default: elem = NULL;
    }
    if (elem == NULL) return;
#else
    if (o[Enum_ov003_02173bd8_212] > 3) {
        return;
    }
    index = data_ov003_0217fa14[o[Enum_ov003_02173bd8_212]];
    elem = func_ov003_02173bb0((Struct_ov003_02173b4c*)((char*)obj + entriesOffset), index);
#endif
    *(int*)((char*)elem + 0x14) = x;
    *(int*)((char*)elem + 0x18) = 0x2f000;
    SpriteContext_DrawSprite((char*)obj + entriesOffset, elem);
}
