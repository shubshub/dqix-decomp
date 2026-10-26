#include <globaldefs.h>
#include "GameState/GameState.h"

void* GameState_GetZoneTransition(GameState* battleStruct);
extern "C" unsigned short* Zone3D_GetInstance(void* fieldPtr);
void InitStruct02070378(char* obj);
struct Vector3i;

// USA: func_ov017_0219bcac
ARM void InitFieldsFromCombatant_0219bcac(unsigned char flag) {
    GameState* battleStruct = GameState::GetInstance();
    char* obj = (char*)GameState_GetZoneTransition(battleStruct);
    unsigned short* val = Zone3D_GetInstance(obj);
    char* combatant = (char*)battleStruct->GetProtagonist();
    InitStruct02070378(obj);
    *(short*)(obj + 0x0) = *val;
    *(Vector3i*)((int*)(obj + 0x10)) = *(Vector3i const*)((int*)(combatant + 0x44));
    *(short*)(obj + 0x1c) = *(int*)(combatant + 0x54);
    *(unsigned char*)(obj + 0x7) = 1;
    *(unsigned char*)(obj + 0x2) = 1;
    *(unsigned char*)(obj + 0x9) = 0;
    *(unsigned char*)(obj + 0xa) = 1;
    *(unsigned char*)(obj + 0x65) = flag;
}
