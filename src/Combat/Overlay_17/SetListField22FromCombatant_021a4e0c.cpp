#include <globaldefs.h>
#include "GameState/GameState.h"

struct PartySelectionState {
    unsigned char unknown00[0x22];
    short selectedPartyIndex;
};

extern "C" void func_ov017_021c12fc(char* resources, unsigned char, unsigned char);

// USA: func_ov017_021a4e0c
ARM void SetListField22FromCombatant_021a4e0c(GameResources* arg0) {
    char* resourceStorage = (char*)arg0;
    GameObject* member = GameState::GetInstance()->GetLeader();
    if (member == NULL) return;
    short index = member->obj3D_.actorIndex_;
    GameResources* resources = arg0;
    PartySelectionState* selection = (PartySelectionState*)resources->unknown_ptr_array_371c[0];
    selection->selectedPartyIndex = index;
    func_ov017_021c12fc(resourceStorage, 1, 1);
}
