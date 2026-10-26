#include <globaldefs.h>
#include "GameState/GameState.h"

extern "C" GameObject* func_0200ff1c(GameState* battleStruct, int combatantId);
struct Struct_0205faf4_11;
extern "C" int func_02061bd8(struct Struct_0205faf4_11* obj);

extern "C" void func_ov017_021919c8(int arg0, int b, short c);
extern "C" void func_ov017_0218fd34(int a, int b, unsigned short e);
extern "C" void func_ov017_0218f968(int a, int b, unsigned short e);

// USA: func_ov017_02191e5c
extern "C" ARM void func_ov017_02191e5c(int a, int b, short c, unsigned char d, unsigned short e) {
	GameState* battleStruct = GameState::GetInstance();
	int var1 = (b >= 0 && b <= 3);
	if (var1) {
		if (!battleStruct->GetPartyMemberByIndex(b)) return;
	}
	GameObject* combatant = battleStruct->GetCombatantByIndex(b);
	if (!combatant) return;
	func_ov017_021919c8(a, b, c);
	combatant->obj3D_.unknown_9c_ = e;
	((Object3D*)((unsigned char*)combatant))->SetField9e(d);
	int var3 = (b >= 0 && b <= 3);
	if (var3) {
		GameObject* c2 = func_0200ff1c(battleStruct, b);
		if (!c2) return;
		if (!func_02061bd8((struct Struct_0205faf4_11*)c2)) {
			func_ov017_0218fd34(a, b, e);
			return;
		}
	}
	func_ov017_0218f968(a, b, e);
}
