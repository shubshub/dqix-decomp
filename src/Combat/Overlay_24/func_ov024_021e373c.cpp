#include <globaldefs.h>
#include "Combat/Overlay_0/GetCombatantByID.h"
#include "GameState/GameState.h"

struct Struct_ov024_021da670_6;
extern "C" int func_ov024_021da998(struct Struct_ov024_021da670_6* obj);
struct Struct_ov024_021dd028_5;
extern "C" int func_ov024_021dd260(struct Struct_ov024_021dd028_5* obj);
extern "C" void func_02087704(void* obj);
extern "C" void func_ov000_02159eac(void* a0, void* buf, int a2);
struct Struct_ov024_021e2bd0;
extern "C" void* func_ov024_021e8ca0(struct Struct_ov024_021e2bd0* obj, int id);
extern "C" void func_ov000_0215cd44(void* a, void* b, void* c, int d, unsigned long long arg4, int g);

struct Struct_ov024_021e373c { char pad0[0x10]; void* unknown_10_; };

// USA: func_ov024_021e373c
extern "C" ARM unsigned long long func_ov024_021e373c(struct Struct_ov024_021e373c* obj, int unused, int id, int arg3, int turns) {
	if (turns <= 0) return 0;
	GameObject* c = GetCombatantByID((int)obj->unknown_10_, id);
	if (!c) return 0;
	if (!func_ov024_021da998((struct Struct_ov024_021da670_6*)c) && !func_ov024_021dd260((struct Struct_ov024_021dd028_5*)c)) return 0;
	func_02087704(c->currentStats_);
	int msg = 0;
	int counter = ((unsigned char*)c->currentStats_)[0x24];
	switch (counter) {
	case 0: msg = 0x17f; break;
	case 1: msg = 0x180; break;
	case 2: msg = 0x181; break;
	case 3: msg = 0x259; break;
	}
	union { struct { int lo; int hi; }; unsigned long long v; } local;
	local.lo = 0;
	local.hi = 0;
	func_ov000_02159eac(obj->unknown_10_, &local, 0x1d);
	if (counter == 3) {
		func_ov000_02159eac(obj->unknown_10_, &local, 8);
	}
	void* entry = func_ov024_021e8ca0((struct Struct_ov024_021e2bd0*)obj, msg);
	if (entry) {
		func_ov000_0215cd44(obj->unknown_10_, entry, c, 0, local.v, 0);
	}
	return local.v;
}
