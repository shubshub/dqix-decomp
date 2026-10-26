#if defined(jpn)
enum { Enum_ov017_02191bdc_14092 = 0x34fc, Enum_ov017_02191bdc_156 = 0x1ec, Enum_ov017_02191bdc_17408 = 0x4000 };
#else
enum { Enum_ov017_02191bdc_14092 = 0x370c, Enum_ov017_02191bdc_156 = 0x9c, Enum_ov017_02191bdc_17408 = 0x4400 };
#endif

#include <globaldefs.h>
#include "Combat/CombatantRecovery.h"
#include "GameState/GameState.h"

extern "C" void* GameState_GetZoneTransition(GameState* battleStruct);
extern "C" GameObject* func_0200ff1c(GameState* battleStruct, int combatantId);

extern "C" void func_ov017_021c9e00(int i, int arg1, int zero, int arg3);

// USA: func_ov017_02191bdc
extern "C" ARM void func_ov017_02191bdc(unsigned char* a, int b) {
	GameState* battleStruct = GameState::GetInstance();
	GameObject* combatant = battleStruct->GetLeader();
	if (!combatant) return;
	if (*(short*)((char*)combatant + 0xac) != 0) return;
	if (combatant->obj3D_.GetFlag(0x8000000) != 0) return;
	if (b == 0) {
		unsigned char* fieldAddr = (unsigned char*)GameState_GetZoneTransition(battleStruct);
		unsigned char* q = *(unsigned char**)(a + Enum_ov017_02191bdc_14092);
		if (q[2] != 0) return;
		if (fieldAddr[2] != 0) return;
	}
	unsigned char* entry = a + Enum_ov017_02191bdc_156 + Enum_ov017_02191bdc_17408;
	for (int i = 0; i < 4; entry += 4, i++) {
		if (entry[0] == 0) continue;
		GameObject* c2 = func_0200ff1c(battleStruct, i);
		if (c2 != NULL) {
			func_02053fe4(c2, *(short*)(entry + 2), 1);
			func_ov017_021c9e00(i, 1, 0, 1);
		}
		entry[0] = 0;
		*(short*)(entry + 2) = 0;
	}
}
