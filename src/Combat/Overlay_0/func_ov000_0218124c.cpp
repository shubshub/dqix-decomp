#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Resource/GameResources.h"

struct Struct0200fb08;
struct BackgroundGraphics;

unsigned char GameState_GetLanguage(struct Struct0200fb08* obj);
void* Background_GetScreen(struct BackgroundGraphics* list, unsigned int index);
void CallFunc0204b620IfField0x14_0204b938(void* a, void* b, int x, int y, unsigned short id);
extern "C" void SpriteContext_DrawSprite(void* dst, void* src);

// USA: func_ov000_0218124c
#if defined(jpn)
extern "C" int func_ov017_021bdbcc(void*);
extern "C" ARM void func_ov000_0218124c(unsigned char* obj, int idx, void* target, int icon, short x, short y) {
    GameObject* member = GameState::GetInstance()->GetPartyMemberByIndex(idx);
    if (member != 0 && *(int*)((char*)member + 0x1b8) != 0) {
        void* entry = Background_GetScreen((BackgroundGraphics*)(obj + 0x8c4), 28);
        CallFunc0204b620IfField0x14_0204b938(target, entry, x, y, (unsigned short)(idx + 2));
        return;
    }
    unsigned char entryIdx = icon + 15;
    if (func_ov017_021bdbcc(GetGameResources()) != 0) entryIdx = 15;
    void* entry = Background_GetScreen((BackgroundGraphics*)(obj + 0x8c4), entryIdx);
    CallFunc0204b620IfField0x14_0204b938(target, entry, x, y, (unsigned short)(idx + 2));
}
#else
extern "C" ARM void func_ov000_0218124c(unsigned char* obj, int idx, void* target, int unused, short x, short y, short posX, short posY) {
    GameState* gs = GameState::GetInstance();
    unsigned int entryIdx = 5;
    switch (GameState_GetLanguage((struct Struct0200fb08*)gs)) {
    case 2:
        var5 = 6;
        break;
    case 3:
        var5 = 8;
        break;
    case 4:
        var5 = 7;
        break;
    case 5:
        var5 = 9;
        break;
    }
    void* entry = Background_GetScreen((struct BackgroundGraphics*)(obj + 0x8c4), entryIdx);
    CallFunc0204b620IfField0x14_0204b938(target, entry, (short)(x + 2), (short)(y + 1), idx + 2);
    GameObject* member = gs->GetPartyMemberByIndex(idx);
    if (member != 0 && *(int*)((char*)member + 0x1c4) == 0) {
        unsigned char* p = *(unsigned char**)(obj + 0x170) + (idx + 0x20) * 0x28;
        *(int*)(p + 0x14) = posX << 12;
        *(int*)(p + 0x18) = posY << 12;
        p[0x22] = idx + 0x5c;
        p[0x26] = 1;
        SpriteContext_DrawSprite(obj + 0x11c, p);
    }
}
#endif
