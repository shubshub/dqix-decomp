#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Combat/Overlay_0/GetCombatantByID.h"

extern "C" int func_02089160(unsigned char* obj);
extern "C" void func_02089174(unsigned char* obj);
extern "C" int func_ov000_0215e958(int a0);

struct Struct_ov024_021e5e80 { char pad[0x10]; int unknown_10_; };

// USA: func_ov024_021e5e80
extern "C" ARM void func_ov024_021e5e80(struct Struct_ov024_021e5e80* s, int id) {
	GameObject* c = GetCombatantByID(s->unknown_10_, id);
	if (!c) return;
	if (!func_02089160((unsigned char*)c->currentStats_)) return;
	if (!func_ov000_0215e958(s->unknown_10_)) return;
	func_02089174((unsigned char*)c->currentStats_);
}
