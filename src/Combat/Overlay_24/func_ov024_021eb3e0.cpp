#include <globaldefs.h>
#include "GameState/GameState.h"

extern "C" unsigned short GameObject_GetPartyMemberLevel(void* obj);

struct Struct_ov024_021eb3e0 {
	char unk[0x3b];
	unsigned char unknown_3b_0_ : 4;
	unsigned char unknown_3b_4_ : 4;
};

// USA: func_ov024_021eb3e0
extern "C" ARM void func_ov024_021eb3e0(void* unused, int combatantId) {
	GameState* battle = GameState::GetInstance();
	GameObject* combatant = func_0200ff1c(battle, combatantId);
	if (combatant == NULL) {
		return;
	}
	struct Struct_ov024_021eb3e0* stats;
	unsigned short value = GameObject_GetPartyMemberLevel(combatant);
	if (value >= 0x4b) {
		stats = (struct Struct_ov024_021eb3e0*)combatant->currentStats_;
		stats->unknown_3b_4_ = 0xa;
		return;
	}
	value = GameObject_GetPartyMemberLevel(combatant);
	if (value >= 0x32) {
		stats = (struct Struct_ov024_021eb3e0*)combatant->currentStats_;
		stats->unknown_3b_4_ = 0x9;
		return;
	}
	value = GameObject_GetPartyMemberLevel(combatant);
	if (value >= 0x19) {
		stats = (struct Struct_ov024_021eb3e0*)combatant->currentStats_;
		stats->unknown_3b_4_ = 0x8;
	} else {
		stats = (struct Struct_ov024_021eb3e0*)combatant->currentStats_;
		stats->unknown_3b_4_ = 0x7;
	}
}
