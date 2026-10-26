#include <globaldefs.h>
#include "Combat/Overlay_0/GetCombatantByID.h"
#include "GameState/GameState.h"

struct Struct_ov024_021da670_7;
extern "C" int func_ov024_021da9b0(struct Struct_ov024_021da670_7* obj);
extern "C" unsigned short func_ov024_021da644(int idx, int a, int b);
extern "C" void func_020882dc(void* obj);
extern "C" void func_ov000_02159eac(void* a0, void* buf, int a2);
extern "C" void* func_ov000_0215e958(void* a0);
extern "C" void func_ov000_0215a88c(void* objRaw, void* arg1, int c);
extern "C" void func_ov000_0215cd44(void* a, void* b, void* c, int d, unsigned long long arg4, int g);

struct Struct_ov024_021dd6f0 {
	unsigned int a : 10;
	unsigned int b : 10;
	unsigned int c : 10;
	unsigned int hi : 2;
};

struct Struct_ov024_021dd6f0_2 { unsigned char pad : 7; unsigned char flag : 1; };
struct Struct_ov024_021dd6f0_3 { unsigned char bit0 : 1; unsigned char rest : 7; };
struct Struct_ov024_021dd6f0_4 { char pad0[0xc]; void* unknown_c_; void* unknown_10_; int unknown_14_; };
struct Struct_ov024_021dd6f0_5 { char pad[0x20]; struct Struct_ov024_021dd6f0 f20; struct Struct_ov024_021dd6f0 f24; };

// USA: func_ov024_021dd6f0
extern "C" ARM void* func_ov024_021dd6f0(struct Struct_ov024_021dd6f0_4* obj, int unused, int id, struct Struct_ov024_021dd6f0_5* range, int arg4, int arg5, unsigned char arg6) {
	GameObject* c = GetCombatantByID((int)obj->unknown_10_, id);
	if (!c) return 0;
	union { struct { int lo; int hi; }; unsigned long long v; } local;
	local.lo = 0;
	local.hi = 0;
	unsigned short sel;
	if (func_ov024_021da9b0((struct Struct_ov024_021da670_7*)c) && arg6 != 0) {
		sel = func_ov024_021da644(id, range->f20.c, range->f24.a);
		func_020882dc((void*)c->currentStats_);
		func_ov000_02159eac(obj->unknown_10_, &local, 0x1a);
		((struct Struct_ov024_021dd6f0_3*)((char*)c->currentStats_ + 0x3b))->bit0 = 1;
		obj->unknown_14_++;
	} else {
		sel = func_ov024_021da644(id, range->f24.b, range->f24.c);
	}
	void* entry = func_ov000_0215e958(obj->unknown_10_);
	if (!entry) return 0;
	func_ov000_0215a88c(obj->unknown_10_, entry, sel);
	struct Struct_ov024_021dd6f0_2* var4 = (struct Struct_ov024_021dd6f0_2*)((char*)obj->unknown_c_ + 0x1c);
	func_ov000_0215cd44(obj->unknown_10_, entry, c, 0, local.v, var4->flag != 0);
	return entry;
}
