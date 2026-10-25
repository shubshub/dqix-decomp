#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Resource/GameResources.h"

struct Obj02061bd8;
int CheckField0x56bLowNibble(struct Obj02061bd8* obj);
extern "C" void func_ov017_02190264(void* h, int i);
void ClearCombatantSlot_0200fd48(GameState* battleStruct, int id);
void* GameState_GetParty(GameState* battleStruct);

// USA: func_ov017_02191484  (semantic: ResetCombatantSlotsAndFlags_02191484)
extern "C" ARM void func_ov017_02191484(unsigned char* obj) {
#if defined(jpn)
 enum {regionalOffset0=0x980};
#else
 enum {regionalOffset0=0xba0};
#endif
    GameState* bs = GameState::GetInstance();
    int h = ((int)GetGameResources());
    for (int i = 0; i < 4; i++) {
        GameObject* c = GetCombatantWithFlag0x100_0200ff1c(bs, i);
        if (c) {
            if (CheckField0x56bLowNibble((struct Obj02061bd8*)c)) {
                func_ov017_02190264((void*)h, i);
            }
        }
    }
    ClearCombatantSlot_0200fd48(bs, 0xce);
    unsigned char* p = (unsigned char*)GameState_GetParty(bs);
    p[0xf7d] = 0;
    unsigned char* p2 = *(unsigned char**)(obj + 0x3000 + regionalOffset0);
    p2[0xb] = 0;
}
