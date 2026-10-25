#include <globaldefs.h>
#include "GameState/GameState.h"

extern "C" void* func_ov011_021849c8(void*);
extern "C" void* func_ov023_021f6880(void*, int);
int ScaleStatsIfType12_021f6f10(void* self);
struct Struct0200fb08;
unsigned char GameState_GetLanguage(struct Struct0200fb08* obj);
void* GetFieldPtrAt_021f79e4_021f79e4(void* obj);

struct Struct_0204b988;
extern "C" void func_0204b988(struct Struct_0204b988*, unsigned int, int, int, unsigned short);

struct BackgroundGraphics;
void Background_DrawScreen(struct BackgroundGraphics*, unsigned int, int, int, short, short, short, short, unsigned short);

void Background_UploadMap(struct BackgroundGraphics*, void*);

struct Struct_ov004_0215de9c;
extern "C" void func_ov023_021fb25c(Struct_ov004_0215de9c*, unsigned int, unsigned int, unsigned int, int);

// USA: func_ov004_02165c04  (semantic: DispatchByNormalizedKindWithExtra_02165c04)
extern "C" ARM int func_ov004_02165c04(void* a) {
    unsigned char v = GameState_GetLanguage((struct Struct0200fb08*)GameState::GetInstance());
    unsigned short extra = 0x4a;
    unsigned int kind = 0;
    switch (v) {
    case 2: kind = 1; extra = 0x5a; break;
    case 4: kind = 2; extra = 0x80; break;
    case 3: kind = 3; break;
    case 5: kind = 4; extra = 0x78; break;
    }

    void* var3 = func_ov023_021f6880(func_ov011_021849c8(arg0), 3);
    if (!var3) return 0;
    if (func_ov024_021f6f10(var3) != 2) return 0;

    *(unsigned char*)((char*)node + 0xc) |= 1;
    void* list = GetFieldPtrAt_021f79e4_021f79e4(node);
    DispatchIndexedEntry0204b988((struct Obj0204b988*)list, 0, 0, 0, 0xffff);
    if (kind != 0) {
        Background_DrawScreen((struct BackgroundGraphics*)list, kind, 0, 0, 0x16, 2, 9, 3, 0xffff);
    }
    Background_UploadMap((struct BackgroundGraphics*)list, 0);

    void* var5 = func_ov023_021f6880(func_ov011_021849c8(arg0), 0x1f8);
    if (var5 && func_ov024_021f6f10(var5) == 1) {
        if (!var5) return 0;
        func_ov023_021fb25c((struct Struct_ov004_0215de9c*)var5, 0, 0, var1, 0x11);
    }
    return 0;
}
