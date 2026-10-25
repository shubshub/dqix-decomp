#include <globaldefs.h>
#include "GameState/GameState.h"

extern "C" void* func_0202ae18(void);
extern "C" int func_0202c540(void* p);
void* GameState_GetParty(GameState* battleStruct);
extern "C" void* Zone3D_GetInstance(void);
extern "C" void func_ov017_021ce400(unsigned char a, unsigned short b);

// USA: func_ov017_021ce4e0
ARM void EnqueueEventIfActive021ce4e0(void) {
    if (func_0202c540(func_0202ae18())) return;
    GameState* battleStruct = GameState::GetInstance();
    unsigned char* base = (unsigned char*)GameState_GetParty(battleStruct);
    if (base[0xf7d] == 0) return;
    unsigned short* p = (unsigned short*)Zone3D_GetInstance();
    func_ov017_021ce400(base[0xf7d], *p);
}
