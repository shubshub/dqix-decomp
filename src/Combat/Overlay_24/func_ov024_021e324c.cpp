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
struct Struct_ov024_021e2bd0;
extern "C" void* func_ov024_021e8ca0(struct Struct_ov024_021e2bd0* obj, int id);
extern "C" void func_ov000_0215cd44(void* a, void* b, void* c, int d, int e, int f, int g);

struct Struct_ov024_021e324c { char pad0[0xc]; void* unknown_c_; void* unknown_10_; };

// USA: func_ov024_021e324c
extern "C" ARM unsigned long long func_ov024_021e324c(struct Struct_ov024_021e324c* obj, int unused, int id) {
	GameObject* c = GetCombatantByID((int)obj->unknown_10_, id);
	if (!c) return 0;
	union { struct { int lo; int hi; }; unsigned long long v; } local;
	local.lo = 0;
	local.hi = 0;
	if (func_020885b4((struct Struct_020885b4*)c->currentStats_) || func_02088514((struct Struct_02088514*)c->currentStats_)) {
		func_02088644((struct Struct_02088644*)c->currentStats_);
		func_ov000_02159eac(obj->unknown_10_, &local, 0x11);
		void* entry = func_ov024_021e8ca0((struct Struct_ov024_021e2bd0*)obj, 0x54);
		if (entry) {
			func_ov000_0215cd44(obj->unknown_10_, entry, c, 0, 0, 0, 0);
		}
	}
	return local.v;
}
