#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Combat/Overlay_0/GetCombatantByID.h"

extern "C" GameObject* func_ov000_021536f8(int unused, int id);

struct Struct_ov024_021e05e4 { char unk[0x18]; int flags; };
struct Struct_ov024_021e04e0 { char unk[0x138]; struct Struct_ov024_021e05e4* inner; };
extern "C" int func_ov024_021e05e4(struct Struct_ov024_021e04e0* obj);

struct S_10088_inner { char unk[0x14]; int flags; };
struct S_10088 { char unk[0x138]; struct S_10088_inner* inner; };
extern "C" int func_02010088(struct S_10088* obj);

// USA: func_ov024_021edf00
extern "C" ARM int func_ov024_021edf00(int* a0, int a1, short* a2) {
	GameObject* c = (GameObject*)func_ov000_021536f8(*a0, a1);
	if (!c) return 0;
	if (!func_ov024_021e05e4((struct Struct_ov024_021e04e0*)c)) return 0;
	short targetId = *(short*)((char*)c->currentStats_ + 0x2e);
	GameObject* c2 = GetCombatantByID(*a0, targetId);
	if (!c2) goto fail;
	if (!func_02010088((struct S_10088*)c2)) {
		*a2 = *(short*)((char*)c->currentStats_ + 0x2e);
		return 1;
	}
fail:
	return 0;
}
