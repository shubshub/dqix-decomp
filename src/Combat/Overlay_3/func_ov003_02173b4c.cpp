#include <globaldefs.h>
#if defined(jpn)
enum { Enum_ov003_02173b4c_236 = 0xe8 };
enum { Enum_ov003_02173b4c_238 = 0xea };
enum { kRegion130 = 0x13c };
enum { Enum_ov003_02173b4c_278528 = 0x4f000 };
#else
enum { Enum_ov003_02173b4c_236 = 0xec };
enum { Enum_ov003_02173b4c_238 = 0xee };
enum { kRegion130 = 0x130 };
enum { Enum_ov003_02173b4c_278528 = 0x44000 };
#endif

struct Struct_ov003_02173b4c;
extern "C" void* func_ov003_02173bb0(Struct_ov003_02173b4c*, unsigned int);
extern "C" void SpriteContext_DrawSprite(void*, void*);

// USA: func_ov003_02173b4c
extern "C" ARM void func_ov003_02173b4c(void* obj) {
    unsigned char* o = (unsigned char*)obj;
    unsigned int flag;
    void* elem;
    if (o[Enum_ov003_02173b4c_236] == 0) {
        return;
    }
    if (o[Enum_ov003_02173b4c_236] == 1) {
        if (o[Enum_ov003_02173b4c_238] < 2) {
            return;
        }
    }
#if defined(jpn)
    if (o[0] != 0) {
        elem = func_ov003_02173bb0((Struct_ov003_02173b4c*)((char*)obj + kRegion130), 1);
    } else {
        elem = func_ov003_02173bb0((Struct_ov003_02173b4c*)((char*)obj + kRegion130), 0);
    }
#else
    flag = 6;
    if (o[0] != 0) {
        flag = 7;
    }
    elem = func_ov003_02173bb0((Struct_ov003_02173b4c*)((char*)obj + kRegion130), flag);
#endif
    if (elem == 0) {
        return;
    }
    *(int*)((char*)elem + 0x14) = Enum_ov003_02173b4c_278528;
    *(int*)((char*)elem + 0x18) = 0x5f000;
    SpriteContext_DrawSprite((char*)obj + kRegion130, elem);
}
