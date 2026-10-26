#include <globaldefs.h>
#include "GameState/GameState.h"
struct GameResources;

GameObject* GetCombatantWithFlag0x100_0200ff1c(GameState* battleStruct, int combatantId);
void* GameObject_GetFloorAttribute(void* obj);
struct ColorHolder0204bd7c;
unsigned short ConvertColorToDecimalOffset30000(struct ColorHolder0204bd7c* obj);
void* GameState_GetZoneTable(void* obj);
struct SearchList02099a68;
int FindKeyGetBitflag02099a68(struct SearchList02099a68* list, unsigned short key);

// USA: func_ov017_021a26e8
ARM int GetBitflagForCombatantColor_021a26e8(GameResources* unused0, int combatantId) {
	GameState* bs = GameState::GetInstance();
	GameObject* combatant = GetCombatantWithFlag0x100_0200ff1c(bs, combatantId);
	if (combatant == NULL) {
		return 0;
	}
	void* p114 = GameObject_GetFloorAttribute(combatant);
	if (p114 == NULL) {
		return 0;
	}
	unsigned short color = ConvertColorToDecimalOffset30000((struct ColorHolder0204bd7c*)p114);
	void* list = GameState_GetZoneTable(bs);
	return FindKeyGetBitflag02099a68((struct SearchList02099a68*)list, color);
}
