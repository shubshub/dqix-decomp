#include <globaldefs.h>
#include "GameState/GameState.h"

struct SearchStruct;

extern "C" void func_02039dd8(unsigned char* obj);
extern "C" void func_0202c660(struct SearchStruct* obj, int value);

// USA: func_ov017_021ceab4
extern "C" ARM void func_ov017_021ceab4(int combatantId, int unused1, int arg2, int arg3, struct SearchStruct* search) {
	GameObject* combatant = GameState::GetInstance()->GetPartyMemberByIndex(combatantId);
	if (combatant != NULL) {
		func_02039dd8((unsigned char*)combatant);
	}
	func_0202c660(search, combatantId);
}
