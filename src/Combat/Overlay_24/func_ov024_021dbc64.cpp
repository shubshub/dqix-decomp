#include <globaldefs.h>
#include "Combat/Overlay_0/GetCombatantByID.h"
#include "GameState/GameState.h"

struct Struct_020885b4;
extern "C" int func_020885b4(struct Struct_020885b4* obj);
struct Struct_02088514;
extern "C" int func_02088514(struct Struct_02088514* obj);
struct Struct_02088644;
extern "C" void func_02088644(struct Struct_02088644* obj);
extern "C" void func_ov000_02159eac(void* a0, void* buf, int a2);
extern "C" unsigned short func_ov024_021da644(int idx, int a, int b);
extern "C" void* func_ov000_0215e958(void* a0);
extern "C" void func_ov000_0215a88c(void* objRaw, void* arg1, int c);
extern "C" void func_ov000_0215cd44(void* a, void* b, void* c, int d, unsigned long long arg4, int g);

struct Struct_ov024_021dbc64_3 {
	unsigned int a : 10;
	unsigned int b : 10;
	unsigned int c : 10;
	unsigned int hi : 2;
};

struct Struct_ov024_021dbc64_4 { unsigned char pad : 7; unsigned char flag : 1; };
struct Struct_ov024_021dbc64_5 { char pad0[0x1c]; struct Struct_ov024_021dbc64_4 flags; };
struct Struct_ov024_021dbc64 {
	char pad0[0xc];
	struct Struct_ov024_021dbc64_5* unknown_c_;
	void* unknown_10_;
	int unknown_14_;
	char pad18[0x75 - 0x18];
	unsigned char unknown_75_;
};
struct Struct_ov024_021dbc64_2 { char pad[0x24]; struct Struct_ov024_021dbc64_3 f24; };

// USA: func_ov024_021dbc64
extern "C" ARM void* func_ov024_021dbc64(struct Struct_ov024_021dbc64* obj, int unused, int id, struct Struct_ov024_021dbc64_2* range, int arg4, int arg5, unsigned char arg6) {
	GameObject* c = GetCombatantByID((int)obj->unknown_10_, id);
	if (!c) return 0;
	union { struct { int lo; int hi; }; unsigned long long v; } local;
	local.lo = 0;
	local.hi = 0;
	int sel;
	if ((func_020885b4((struct Struct_020885b4*)c->currentStats_) || func_02088514((struct Struct_02088514*)c->currentStats_)) && arg6 != 0) {
		sel = 0x54;
		func_02088644((struct Struct_02088644*)c->currentStats_);
		func_ov000_02159eac(obj->unknown_10_, &local, 0x11);
		obj->unknown_14_++;
	} else {
		sel = func_ov024_021da644(id, range->f24.b, range->f24.c);
		obj->unknown_75_ = 0;
	}
	void* entry = func_ov000_0215e958(obj->unknown_10_);
	if (!entry) return 0;
	func_ov000_0215a88c(obj->unknown_10_, entry, sel);
	func_ov000_0215cd44(obj->unknown_10_, entry, c, 0, local.v, obj->unknown_c_->flags.flag != 0);
	return entry;
}
