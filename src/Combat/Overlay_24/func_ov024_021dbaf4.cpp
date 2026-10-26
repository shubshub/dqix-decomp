#include <globaldefs.h>
#include "Combat/Overlay_0/GetCombatantByID.h"
#include "GameState/GameState.h"

extern "C" int func_02088540(unsigned char* obj);
struct Struct_020885e0;
extern "C" int func_020885e0(struct Struct_020885e0* obj);
struct Struct_ov024_021dbaf4_4;
extern "C" int func_ov024_021e939c(struct Struct_ov024_021dbaf4_4* ctx, int id, int flag1, int flag2);
extern "C" int func_ov024_021eb4b0(int a0, int flags, int mask);
extern "C" void func_ov000_02159eac(void* a0, void* buf, int a2);
extern "C" void func_02088560(unsigned char* obj);
struct Struct_02088624;
extern "C" void func_02088624(struct Struct_02088624* obj);
extern "C" void* func_ov000_0215e958(void* a0);
extern "C" void func_ov024_021e8bf0(void* work, void* fieldC, unsigned short* sel);
extern "C" void func_ov000_0215a88c(void* objRaw, void* arg1, int c);
extern "C" void func_ov000_0215cd44(void* a, void* b, void* c, int d, unsigned long long arg4, int g);

struct Struct_ov024_021dbaf4_5 { unsigned char pad : 7; unsigned char flag : 1; };
struct Struct_ov024_021dbaf4 { char pad0[0xc]; void* unknown_c_; void* unknown_10_; };
struct Struct_ov024_021dbaf4_2 { char pad[0x30]; short unknown_30_; };
struct Struct_ov024_021dbaf4_3 { char pad[0x14]; int field14; };

// USA: func_ov024_021dbaf4
extern "C" ARM void* func_ov024_021dbaf4(struct Struct_ov024_021dbaf4* obj, int unused, int id, struct Struct_ov024_021dbaf4_2* action, int arg4, int arg5, unsigned char arg6) {
	GameObject* c = GetCombatantByID((int)obj->unknown_10_, id);
	if (!c) return 0;
	int apply = 0;
	int full = apply;
	if (action->unknown_30_ > 0) {
		if (func_02088540((unsigned char*)c->currentStats_) && arg6) {
			apply = 1;
			full = apply;
		}
	} else {
		if (func_020885e0((struct Struct_020885e0*)c->currentStats_) && arg6) {
			apply = 1;
		}
	}
	unsigned short sel = func_ov024_021e939c((struct Struct_ov024_021dbaf4_4*)obj, id, full, apply);
	union { struct { int lo; int hi; }; unsigned long long v; } local;
	local.lo = 0;
	local.hi = 0;
	if (apply) {
		if (func_ov024_021eb4b0((int)obj, ((struct Struct_ov024_021dbaf4_3*)c->currentStats_)->field14, 2)) {
			func_ov000_02159eac(obj->unknown_10_, &local, 0x2b);
		}
		if (full) {
			func_02088560((unsigned char*)c->currentStats_);
		} else {
			func_02088624((struct Struct_02088624*)c->currentStats_);
		}
		func_ov000_02159eac(obj->unknown_10_, &local, 0xf);
	}
	void* entry = func_ov000_0215e958(obj->unknown_10_);
	if (!entry) return 0;
	func_ov024_021e8bf0(obj, obj->unknown_c_, &sel);
	func_ov000_0215a88c(obj->unknown_10_, entry, sel);
	struct Struct_ov024_021dbaf4_5* var6 = (struct Struct_ov024_021dbaf4_5*)((char*)obj->unknown_c_ + 0x1c);
	func_ov000_0215cd44(obj->unknown_10_, entry, c, 0, local.v, var6->flag != 0);
	return entry;
}
