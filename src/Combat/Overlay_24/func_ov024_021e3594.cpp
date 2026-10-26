#include <globaldefs.h>
#include "Combat/Overlay_0/GetCombatantByID.h"
#include "GameState/GameState.h"
#include "Util/Random.h"

struct Struct_ov024_021e3594 { unsigned char pad : 7; unsigned char flag : 1; };
struct Struct_ov024_021e3594_2 { char pad0[0x1c]; struct Struct_ov024_021e3594 flags; };
struct Struct_ov024_021e3594_3 { char pad0[0xc]; struct Struct_ov024_021e3594_2* ctx; void* unknown_10_; };
struct Struct_ov024_021e3594_4 {
	char pad0[4];
	unsigned int id : 12;
	unsigned int unknown_5_4_ : 20;
	char pad8[0x32 - 8];
	short stage;
};
struct Struct_ov024_021e3594_5 { char pad0[0x50]; unsigned char unknown_50_; };

struct Struct_02087860;
extern "C" int func_02087860(Struct_02087860* p, unsigned char arg1);
struct Struct_020878b4;
extern "C" int func_020878b4(struct Struct_020878b4* p, int delta);
void UpdateCombatantDefense(int unused, int combatantId);
extern "C" int func_ov024_021e95d4(struct Struct_ov024_021e3594_3* ctx, int id, struct Struct_ov024_021e3594_4* params, unsigned char mode, signed char arg4, unsigned char changed, unsigned char flag);
extern "C" void func_ov000_02159eac(void* a0, void* buf, int a2);
struct Struct_ov024_021e2bd0;
extern "C" void* func_ov024_021e8ca0(struct Struct_ov024_021e2bd0* obj, int id);
extern "C" void func_ov000_0215cd44(void* a, void* b, void* c, int d, int e, int f, int g);

// USA: func_ov024_021e3594
extern "C" ARM unsigned long long func_ov024_021e3594(struct Struct_ov024_021e3594_3* obj, int unused, int id, struct Struct_ov024_021e3594_4* action, int count) {
	if (count <= 0) return 0;
	GameObject* c = GetCombatantByID((int)obj->unknown_10_, id);
	if (!c) return 0;
	int roll = NextRandomMax((struct Random*)obj->unknown_10_, 100);
	int stage = action->stage;
	if (stage < -2) stage = -2;
	if (stage > 2) stage = 2;
	int var3 = 0;
	if (stage < 0) {
		if (action->id != 0xad) {
			unsigned char rate = ((struct Struct_ov024_021e3594_5*)c->currentStats_)->unknown_50_;
			if (rate == 0) return 0;
			if (!obj->ctx->flags.flag) {
				float var5 = rate;
				if (roll >= rate) return 0;
			}
		}
		var3 = 1;
	}
	int changed = 0;
	int delta = 0;
	if (func_02087860((struct Struct_02087860*)c->currentStats_, var3)) {
		delta = func_020878b4((struct Struct_020878b4*)c->currentStats_, (signed char)stage);
		UpdateCombatantDefense((int)obj->unknown_10_, id);
		changed = 1;
	}
	union { struct { int lo; int hi; }; unsigned long long v; } local;
	local.lo = 0;
	local.hi = 0;
	if (changed) {
		int msg = func_ov024_021e95d4(obj, id, action, var3, delta, 1, 1);
		func_ov000_02159eac(obj->unknown_10_, &local, 0x1e);
		void* entry = func_ov024_021e8ca0((struct Struct_ov024_021e2bd0*)obj, msg);
		if (entry) {
			func_ov000_0215cd44(obj->unknown_10_, entry, c, 0, 0, 0, 0);
		}
	}
	return local.v;
}
