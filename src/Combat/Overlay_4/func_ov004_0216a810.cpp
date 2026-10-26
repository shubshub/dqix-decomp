#include <globaldefs.h>
#include "GameState/GameState.h"

extern "C" void* func_ov011_021849c8(void*);
extern "C" void* func_ov023_021f6880(void*, int);
extern "C" int func_ov024_021f6f10(void* self);
struct Struct0200fb08;
extern "C" unsigned char GameState_GetLanguage(struct Struct0200fb08* obj);
struct Struct_ov004_0215de9c;
extern "C" void func_ov023_021fb25c(Struct_ov004_0215de9c* obj, unsigned int a, unsigned int b, unsigned int c, int d);

// USA: func_ov004_0216a810
extern "C" ARM int func_ov004_0216a810(void* a) {
    GameState* battle = GameState::GetInstance();
    void* base = func_ov011_021849c8(a);
    struct Struct_ov004_0215de9c* var2 = (struct Struct_ov004_0215de9c*)func_ov023_021f6880(base, 0x1e);
    if (!var2) return 0;
    if (func_ov024_021f6f10(var2) != 1) return 0;
    switch (GameState_GetLanguage((struct Struct0200fb08*)battle)) {
        case 1: func_ov023_021fb25c(var2, 0, 0, 0x58, 0x10); break;
        case 2: func_ov023_021fb25c(var2, 0, 0, 0x50, 0x10); break;
        case 3: func_ov023_021fb25c(var2, 0, 0, 0x50, 0x10); break;
        case 4: func_ov023_021fb25c(var2, 0, 0, 0x60, 0x10); break;
        case 5: func_ov023_021fb25c(var2, 0, 0, 0x60, 0x10); break;
    }
    struct Struct_ov004_0215de9c* obj2 = (struct Struct_ov004_0215de9c*)func_ov023_021f6880(base, 0x1f);
    if (!obj2) return 0;
    if (func_ov024_021f6f10(obj2) != 1) return 0;
    switch (GameState_GetLanguage((struct Struct0200fb08*)battle)) {
        case 1: func_ov023_021fb25c(obj2, 8, 0, 0x58, 0x10); break;
        case 2: func_ov023_021fb25c(obj2, 0x10, 0, 0x50, 0x10); break;
        case 3: func_ov023_021fb25c(obj2, 0x10, 0, 0x50, 0x10); break;
        case 4: func_ov023_021fb25c(obj2, 0, 0, 0x60, 0x10); break;
        case 5: func_ov023_021fb25c(obj2, 0, 0, 0x60, 0x10); break;
    }
    return 0;
}
