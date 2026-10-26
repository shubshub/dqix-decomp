#include <globaldefs.h>
#include "GameState/GameState.h"

extern "C" void* func_ov011_021849c8(void*);
extern "C" void* func_ov023_021f6880(void*, int);
extern "C" int func_ov024_021f6f10(void* self);
struct Struct0200fb08;
extern "C" unsigned char GameState_GetLanguage(struct Struct0200fb08* obj);
extern "C" void* func_ov023_021f79e4(void* obj);

struct Struct_0204b988;
extern "C" void func_0204b988(struct Struct_0204b988*, unsigned int, int, int, unsigned short);

struct BackgroundGraphics;
extern "C" void Background_DrawScreen(struct BackgroundGraphics*, unsigned int, int, int, short, short, short, short, unsigned short);

extern "C" void Background_UploadMap(struct BackgroundGraphics*, void*);

// USA: func_ov004_02156cb8
extern "C" ARM int func_ov004_02156cb8(void* a) {
    unsigned char v = GameState_GetLanguage((struct Struct0200fb08*)GameState::GetInstance());
    int kind = 0;
    switch (v) {
    case 2: kind = 1; break;
    case 4: kind = 2; break;
    case 3: kind = 3; break;
    case 5: kind = 4; break;
    }

    void* node = func_ov023_021f6880(func_ov011_021849c8(a), 0x28);
    if (!node) return 0;
    if (func_ov024_021f6f10(node) != 2) return 0;

    *(unsigned char*)((char*)node + 0xc) |= 1;
    void* list = func_ov023_021f79e4(node);
    func_0204b988((struct Struct_0204b988*)list, 0, 0, 0, 0xffff);
    if (kind != 0) {
        Background_DrawScreen((struct BackgroundGraphics*)list, kind, 0, 0, 0x16, 2, 9, 2, 0xffff);
    }
    Background_UploadMap((struct BackgroundGraphics*)list, 0);
    return 0;
}
