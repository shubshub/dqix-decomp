#include <globaldefs.h>
#include "Combat/Overlay_0/GetCombatantByID.h"
#include "GameState/GameState.h"

struct Struct_02087b3c;
struct Struct_02087b90;
extern "C" int func_02087b3c(struct Struct_02087b3c* p, int arg1);
extern "C" int func_02087b90(struct Struct_02087b90* p, int delta);
void UpdateCombatantMagicalMight(int unused, int combatantId);
extern "C" void func_ov000_02159eac(void* a0, void* buf, int a2);
struct Struct_ov024_021e2bd0;
extern "C" void* func_ov024_021e8ca0(struct Struct_ov024_021e2bd0* obj, int id);
extern "C" void func_ov000_0215cd44(void* a, void* b, void* c, int d, int e, int f, int g);

struct Struct_ov024_021e4158 { char pad0[0xc]; void* unknown_c_; void* unknown_10_; };
struct Struct_ov024_021e4158_2 { char pad[0x32]; short unknown_32_; };

// USA: func_ov024_021e4158
extern "C" ARM unsigned long long func_ov024_021e4158(struct Struct_ov024_021e4158* obj, int unused, int id, struct Struct_ov024_021e4158_2* range) {
	GameObject* c = GetCombatantByID((int)obj->unknown_10_, id);
	if (!c) return 0;
	int delta = range->unknown_32_;
	if (delta < -2) delta = -2;
	if (delta > 2) delta = 2;
	int var2 = 0;
	if (delta < 0) var2 = 1;
	int var3 = 0;
	int stage = 0;
	if (func_02087b3c((struct Struct_02087b3c*)c->currentStats_, (unsigned char)var2)) {
		stage = func_02087b90((struct Struct_02087b90*)c->currentStats_, (signed char)delta);
		UpdateCombatantMagicalMight((int)obj->unknown_10_, id);
		var3 = 1;
	}
	union { struct { int lo; int hi; }; unsigned long long v; } local;
	local.lo = 0;
	local.hi = 0;
	if (var3) {
		int msg;
		if (delta > 0) {
			switch (stage) {
			case 2: msg = 0xd0; break;
			case 0: msg = 0x1b7; break;
			default: msg = 0xd1; break;
			}
		} else {
			switch (stage) {
			case -2: msg = 0x1b6; break;
			case 0: msg = 0x1b7; break;
			default: msg = 0x1b5; break;
			}
		}
		func_ov000_02159eac(obj->unknown_10_, &local, 0x20);
		void* entry = func_ov024_021e8ca0((struct Struct_ov024_021e2bd0*)obj, msg);
		if (entry) {
			func_ov000_0215cd44(obj->unknown_10_, entry, c, 0, 0, 0, 0);
		}
	}
	return local.v;
}
