#include <globaldefs.h>
#include "GameState/GameState.h"
struct GameResources;

extern "C" GameObject* func_0200ff1c(GameState* battleStruct, int combatantId);
extern "C" void* GameObject_GetFloorAttribute(void* obj);
struct ColorHolder0204bd7c;
extern "C" unsigned short func_0204bd7c(struct ColorHolder0204bd7c* obj);
extern "C" void* GameState_GetZoneTable(void* obj);
struct SearchList02099a68;
extern "C" int func_02099a68(struct SearchList02099a68* list, unsigned short key);

// USA: func_ov017_021a26e8
extern "C" ARM int func_ov017_021a26e8(GameResources* unused0, int combatantId) {
	GameState* bs = GameState::GetInstance();
	GameObject* combatant = func_0200ff1c(bs, combatantId);
	if (combatant == NULL) {
		return 0;
	}
	void* p114 = GameObject_GetFloorAttribute(combatant);
	if (p114 == NULL) {
		return 0;
	}
	unsigned short color = func_0204bd7c((struct ColorHolder0204bd7c*)p114);
	void* list = GameState_GetZoneTable(bs);
	return func_02099a68((struct SearchList02099a68*)list, color);
}
