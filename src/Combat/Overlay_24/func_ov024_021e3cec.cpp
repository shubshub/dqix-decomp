#include <globaldefs.h>
#include "Combat/Overlay_0/GetCombatantByID.h"
#include "GameState/GameState.h"

extern "C" void func_ov024_021ea85c(void* obj, int id, int a2);
extern "C" void func_ov000_02159eac(void* a0, void* buf, int a2);
struct Struct_ov024_021e2bd0;
extern "C" void* func_ov024_021e8ca0(struct Struct_ov024_021e2bd0* obj, int id);
extern "C" void func_ov000_0215cd44(void* a, void* b, void* c, int d, unsigned long long arg4, int g);

struct Struct_ov024_021e3cec { char pad0[0x10]; void* unknown_10_; };

// USA: func_ov024_021e3cec
extern "C" ARM unsigned long long func_ov024_021e3cec(struct Struct_ov024_021e3cec* obj, int unused, int id) {
	GameObject* c = GetCombatantByID((int)obj->unknown_10_, id);
	if (!c) return 0;
	func_ov024_021ea85c(obj, id, 1);
	union { struct { int lo; int hi; }; unsigned long long v; } local;
	local.lo = 0;
	local.hi = 0;
	func_ov000_02159eac(obj->unknown_10_, &local, 0x28);
	void* entry = func_ov024_021e8ca0((struct Struct_ov024_021e2bd0*)obj, 0);
	if (entry) {
		func_ov000_0215cd44(obj->unknown_10_, entry, c, 0, local.v, 0);
	}
	return 0;
}
