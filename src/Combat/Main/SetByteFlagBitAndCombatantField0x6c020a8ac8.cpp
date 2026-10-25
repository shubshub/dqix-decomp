#include <globaldefs.h>
#include "GameState/GameState.h"

void FlagWord_SetBits(unsigned int* p, unsigned int mask);
void* GlobalFlags_GetInstance(void);

// USA: func_020a8ac8
ARM void SetByteFlagBitAndCombatantField0x6c_020a8ac8(unsigned char* obj, int bit) {
    *(unsigned char*)(obj + 4) |= (1 << bit);
    FlagWord_SetBits((unsigned int*)GlobalFlags_GetInstance(), 0x402);
    ((Object3D*)((unsigned char*)GameState::GetInstance()->GetPartyMemberByIndex(bit)))->EnableFlag(0x8000100);
}
