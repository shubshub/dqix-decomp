#include <globaldefs.h>
#include "GameState/GameState.h"

extern "C" void FlagWord_SetBits(unsigned int* p, unsigned int mask);
extern "C" void* GlobalFlags_GetInstance(void);

// USA: func_020a8ac8
extern "C" ARM void func_020a8ac8(unsigned char* obj, int bit) {
    *(unsigned char*)(obj + 4) |= (1 << bit);
    FlagWord_SetBits((unsigned int*)GlobalFlags_GetInstance(), 0x402);
    ((Object3D*)((unsigned char*)GameState::GetInstance()->GetPartyMemberByIndex(bit)))->EnableFlag(0x8000100);
}
