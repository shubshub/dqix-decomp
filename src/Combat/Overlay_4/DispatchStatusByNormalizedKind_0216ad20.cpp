#include <globaldefs.h>
#include "GameState/GameState.h"

extern "C" void* func_ov011_021849c8(void*);
extern "C" void* func_ov023_021f6880(void*, int);
int ScaleStatsIfType12_021f6f10(void* self);
struct Struct0200fb08;
unsigned char GameState_GetLanguage(struct Struct0200fb08* obj);
void* GetFieldPtrAt_021f79e4_021f79e4(void* obj);

struct Obj0204b988;
void DispatchIndexedEntry0204b988(struct Obj0204b988*, unsigned int, int, int, unsigned short);

struct BackgroundGraphics;
void Background_DrawScreen(struct BackgroundGraphics*, unsigned int, int, int, short, short, short, short, unsigned short);

void Background_UploadMap(struct BackgroundGraphics*, void*);

// USA: func_ov004_0216ad20  (semantic: DispatchStatusByNormalizedKind_0216ad20)
extern "C" ARM int func_ov004_0216ad20(void* a) {
    unsigned char v = GameState_GetLanguage((struct Struct0200fb08*)GameState::GetInstance());
    int kind = 0;
    switch (v) {
    case 2: kind = 1; break;
    case 4: kind = 2; break;
    case 3: kind = 3; break;
    case 5: kind = 4; break;
    }

    void* node = func_ov023_021f6880(func_ov011_021849c8(a), 0x67);
    if (!node) return 0;
    if (ScaleStatsIfType12_021f6f10(node) != 2) return 0;

    *(unsigned char*)((char*)node + 0xc) |= 1;
    void* list = GetFieldPtrAt_021f79e4_021f79e4(node);
    DispatchIndexedEntry0204b988((struct Obj0204b988*)list, 0, 0, 0, 0xffff);
    if (kind != 0) {
        Background_DrawScreen((struct BackgroundGraphics*)list, kind, 0, 0, 2, 2, 0x1c, 2, 0xffff);
    }
    Background_UploadMap((struct BackgroundGraphics*)list, 0);
    return 0;
}
