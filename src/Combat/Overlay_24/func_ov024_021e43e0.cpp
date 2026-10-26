#include <globaldefs.h>
#include "Combat/Overlay_0/GetCombatantByID.h"
#include "GameState/GameState.h"
#include "Util/Random.h"

struct Struct_ov024_021e43e0 { char pad0[0x10]; void* unknown_10_; };
struct Struct_ov024_021e43e0_2 {
	char pad0[0x14];
	unsigned int unknown_14_0_ : 7;
	unsigned int unknown_14_7_ : 7;
	unsigned int unknown_15_6_ : 18;
	char pad18[0x32 - 0x18];
	short code;
};
struct Struct_ov024_021e43e0_3 {
	char pad0[0x14];
	int flags;
	char pad18[0x22 - 0x18];
	unsigned short unknown_22_0_ : 6;
	unsigned short code : 3;
	unsigned short rest : 7;
	char pad24[0x46 - 0x24];
	unsigned char unknown_46_;
};

extern "C" int func_02088840(unsigned char* obj);
extern "C" int func_ov024_021e9198(struct Struct_ov024_021e43e0* ctx, int id, short code, int mode);
extern "C" int func_ov024_021eb4b0(int a0, int flags, int mask);
extern "C" void func_ov000_02159eac(void* a0, void* buf, int a2);
extern "C" void func_02088854(unsigned char* obj);
struct Struct_ov024_021e2bd0;
extern "C" void* func_ov024_021e8ca0(struct Struct_ov024_021e2bd0* obj, int id);
extern "C" void func_ov000_0215cd44(void* a, void* b, void* c, int d, int e, int f, int g);

static inline int IsPartyMember(int id) {
	return id >= 0 && id <= 3;
}

// USA: func_ov024_021e43e0
extern "C" ARM unsigned long long func_ov024_021e43e0(struct Struct_ov024_021e43e0* obj, int arg1, int id, struct Struct_ov024_021e43e0_2* action, int count) {
	if (count <= 0) return 0;
	GameObject* c = GetCombatantByID((int)obj->unknown_10_, id);
	if (!c) return 0;
	int roll = NextRandomMax((struct Random*)obj->unknown_10_, 100);
	float base;
	if (IsPartyMember(arg1)) {
		base = action->unknown_14_7_;
	} else {
		base = action->unknown_14_0_;
	}
	struct Struct_ov024_021e43e0_3* stats = (struct Struct_ov024_021e43e0_3*)c->currentStats_;
	float var4 = base * (stats->unknown_46_ / 100.0f);
	int msg = 0;
	union { struct { int lo; int hi; }; unsigned long long v; } local;
	local.lo = 0;
	local.hi = 0;
	int code = action->code;
	if (func_02088840((unsigned char*)c->currentStats_) && roll < var4) {
		msg = func_ov024_021e9198(obj, id, code, 1);
		if (!msg) msg = 0xf5;
		if (func_ov024_021eb4b0((int)obj, ((struct Struct_ov024_021e43e0_3*)c->currentStats_)->flags, 0x40)) {
			func_ov000_02159eac(obj->unknown_10_, &local, 0x2b);
		}
		func_02088854((unsigned char*)c->currentStats_);
		((struct Struct_ov024_021e43e0_3*)c->currentStats_)->code = (unsigned char)code;
	}
	void* entry = func_ov024_021e8ca0((struct Struct_ov024_021e2bd0*)obj, msg);
	if (entry) {
		func_ov000_0215cd44(obj->unknown_10_, entry, c, 0, 0, 0, 0);
	}
	return 0;
}
