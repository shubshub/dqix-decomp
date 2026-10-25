#include <globaldefs.h>
#include "GameState/GameState.h"

struct AngleTrig0202e9a4;
void CharacterModel_Destroy(void*);
int GetFieldIfFlag4_020100f8(char*);
void FollowCamera_EnableFollow(void*);
void SetAngleAndTrigTable0202e9a4(struct AngleTrig0202e9a4*, int);

// USA: func_ov023_021fc6cc
ARM void ReinitEntriesAndAngle021fc6cc(void* obj) {
    for (int i = 0; i < 2; i++) {
        CharacterModel_Destroy((char*)obj + 0x20 + i * 0xc20);
    }
    void* p = (void*)GetFieldIfFlag4_020100f8((char*)GameState::GetInstance());
    FollowCamera_EnableFollow(p);
    SetAngleAndTrigTable0202e9a4((struct AngleTrig0202e9a4*)p, *(int*)((char*)obj + 0x1000 + 0x860));
}
