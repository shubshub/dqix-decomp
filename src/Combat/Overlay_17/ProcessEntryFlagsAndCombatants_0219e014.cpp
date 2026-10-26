#include <globaldefs.h>
#include "GameState/GameState.h"

struct Entry_02028bd0;
struct Entry_02028bd0* ZoneRecords_GetInstance(void);
extern "C" void* LinkSession_GetInstance(void);
int LinkSession_IsActive(int* obj);
struct SearchStruct0202c1a4;
signed char LinkSession_GetOwnSlot(struct SearchStruct0202c1a4* obj);
extern "C" void FieldMonsterState_Init(void* obj);

struct EntryArg_0219e014 { unsigned char pad0[2]; unsigned short field2 : 2; unsigned short pad3 : 14; };

// USA: func_ov017_0219e014
ARM void ProcessEntryFlagsAndCombatants_0219e014(unsigned char* obj, EntryArg_0219e014* entry) {
	GameState* battleStruct = GameState::GetInstance();
	ZoneRecords_GetInstance();
	void* search = LinkSession_GetInstance();

	if (entry) {
		for (int i = 0; i < 0xc; i++) {
			unsigned int idx = entry->field2;
			int combatantId = i + (idx * 0xc + 0x70);
			GameObject* combatant = battleStruct->GetFieldMonsterByIndex(combatantId);

			if (combatant) {
				if (LinkSession_IsActive((int*)search) && LinkSession_GetOwnSlot((struct SearchStruct0202c1a4*)search) != 0) {
					FieldMonsterState_Init(combatant);
					((Object3D*)((unsigned char*)combatant))->MakeHidden();
				} else {
					((Object3D*)((unsigned char*)combatant))->Destroy();
				}
			}
		}
	}

	for (int i = 7; i <= 0x12; i++) {
		GameObject* combatant = battleStruct->GetGameObjectByIndex(i);
		if (combatant) {
			combatant->obj3D_.Initialize();
			((Object3D*)((unsigned char*)combatant))->MakeHidden();
		}
	}
}
