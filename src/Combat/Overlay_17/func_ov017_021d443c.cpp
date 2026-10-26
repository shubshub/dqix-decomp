#include <globaldefs.h>
#include "GameState/GameState.h"


struct Struct_02039d84;
extern "C" void func_02039d84(struct Struct_02039d84* obj);

// USA: func_ov017_021d443c
extern "C" ARM void func_ov017_021d443c(int a, signed char* b, GameState* battle) {
	int id = a;
	signed char v = b[4];
	if (v != -1) {
		id = v;
	}
	GameObject* c = battle->GetPartyMemberByIndex(id);
	if (c) {
		func_02039d84((struct Struct_02039d84*)c);
	}
}
