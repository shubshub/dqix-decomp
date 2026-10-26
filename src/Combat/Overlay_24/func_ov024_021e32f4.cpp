#include <globaldefs.h>
#include "Combat/Overlay_0/GetCombatantByID.h"
#include "GameState/GameState.h"

struct Struct_ov024_021da670_7;
extern "C" int func_ov024_021da9b0(struct Struct_ov024_021da670_7* obj);
extern "C" void func_020882dc(void* obj);
extern "C" void func_ov000_02159eac(void* a0, void* buf, int a2);
struct Struct_ov024_021e2bd0;
extern "C" void* func_ov024_021e8ca0(struct Struct_ov024_021e2bd0* obj, int id);
extern "C" void func_ov000_0215cd44(void* a, void* b, void* c, int d, int e, int f, int g);

struct Struct_ov024_021e32f4 { char pad0[0xc]; void* unknown_c_; void* unknown_10_; };
struct Struct_ov024_021e32f4_2 { unsigned char bit0 : 1; unsigned char rest : 7; };

// USA: func_ov024_021e32f4
extern "C" ARM unsigned long long func_ov024_021e32f4(struct Struct_ov024_021e32f4* obj, int unused, int id) {
	GameObject* c = GetCombatantByID((int)obj->unknown_10_, id);
	if (!c) return 0;
	union { struct { int lo; int hi; }; unsigned long long v; } local;
	local.lo = 0;
	local.hi = 0;
	if (func_ov024_021da9b0((struct Struct_ov024_021da670_7*)c)) {
		func_020882dc((void*)c->currentStats_);
		func_ov000_02159eac(obj->unknown_10_, &local, 0x1a);
		((struct Struct_ov024_021e32f4_2*)((char*)c->currentStats_ + 0x3b))->bit0 = 1;
		void* entry = func_ov024_021e8ca0((struct Struct_ov024_021e2bd0*)obj, 0x1f9);
		if (entry) {
			func_ov000_0215cd44(obj->unknown_10_, entry, c, 0, 0, 0, 0);
		}
	}
	return local.v;
}
