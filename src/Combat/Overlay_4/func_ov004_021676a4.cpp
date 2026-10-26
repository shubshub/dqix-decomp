#include <globaldefs.h>
#include "GameState/GameState.h"

struct Struct0200fb08;
extern "C" unsigned char GameState_GetLanguage(struct Struct0200fb08* obj);

extern "C" void* func_ov011_021849c8(void* a);

struct Struct_ov004_021676a4 { char pad[0xc]; unsigned char f0c; };
extern "C" Struct_ov004_021676a4* func_ov023_021f6880(void* obj, int key);

extern "C" int func_ov024_021f6f10(void* self);
extern "C" void* func_ov023_021f79e4(void* obj);

struct Struct_0204b988;
extern "C" void func_0204b988(struct Struct_0204b988* obj, unsigned int index, int a3, int a4, unsigned short a5);
struct BackgroundGraphics;
extern "C" void Background_DrawScreen(struct BackgroundGraphics*, unsigned int, int, int, short, short, short, short, unsigned short);
extern "C" void Background_UploadMap(struct BackgroundGraphics* obj, void* buf);

// USA: func_ov004_021676a4
extern "C" ARM int func_ov004_021676a4(void* a) {
    int lang = GameState_GetLanguage((struct Struct0200fb08*)GameState::GetInstance());
    unsigned int v = 1;
    switch (lang) {
    case 2:
        v = 2;
        break;
    case 4:
        v = 3;
        break;
    case 3:
        v = 4;
        break;
    case 5:
        v = 5;
        break;
    }

    void* obj = func_ov011_021849c8(a);
    Struct_ov004_021676a4* node = func_ov023_021f6880(obj, 0xd);
    if (!node) return 0;
    if (func_ov024_021f6f10(node) != 2) return 0;

    node->f0c |= 1;
    void* field = func_ov023_021f79e4(node);
    func_0204b988((struct Struct_0204b988*)field, 1, 0, 0, 0xffff);

    if (v > 1) {
        Background_DrawScreen((struct BackgroundGraphics*)field, v, 0, 0, 0x16, 2, 9, 2, 0xffff);
    }
    Background_UploadMap((struct BackgroundGraphics*)field, 0);
    return 0;
}
