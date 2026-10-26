#include <globaldefs.h>
#include "Combat/Overlay_0/GetCombatantByID.h"
#include "GameState/GameState.h"

struct Struct_02087c30;
extern "C" int func_02087c30(Struct_02087c30*, unsigned char);
struct Struct_02087c84;
extern "C" int func_02087c84(struct Struct_02087c84* p, int delta);
void UpdateCombatantMagicalMending(int random, int combatantId);
struct Struct_ov024_021dee84_4;
struct Struct_ov024_021e47f4;
extern "C" int func_ov024_021e9990(Struct_ov024_021dee84_4*, int, int, unsigned char, signed char);
extern "C" void func_ov000_02159eac(void* a0, void* buf, int a2);
struct Struct_ov024_021e2bd0;
extern "C" void* func_ov024_021e8ca0(struct Struct_ov024_021e2bd0* obj, int id);
extern "C" void func_ov000_0215cd44(void* a, void* b, void* c, int d, int e, int f, int g);

struct Struct_ov024_021e47f4_2 { char pad0[0x10]; void* unknown_10_; };
struct Struct_ov024_021e47f4 { char pad0[0x32]; short unknown_32_; };

// USA: func_ov024_021e47f4
extern "C" ARM unsigned long long func_ov024_021e47f4(struct Struct_ov024_021e47f4_2* obj, int unused, int id, struct Struct_ov024_021e47f4* info) {
	GameObject* c = GetCombatantByID((int)obj->unknown_10_, id);
	if (!c) return 0;
	int delta = info->unknown_32_;
	if (delta < -2) delta = -2;
	if (delta > 2) delta = 2;
	int var2 = 0;
	if (delta < 0) var2 = 1;
	int var3 = 0;
	int result = 0;
	if (func_02087c30((struct Struct_02087c30*)c->currentStats_, var2)) {
		result = func_02087c84((struct Struct_02087c84*)c->currentStats_, (signed char)delta);
		UpdateCombatantMagicalMending((int)obj->unknown_10_, id);
		var3 = 1;
	}
	union { struct { int lo; int hi; }; unsigned long long v; } local;
	local.lo = 0;
	local.hi = 0;
	if (var3) {
		int code = func_ov024_021e9990((struct Struct_ov024_021dee84_4*)obj, id, (int)info, var2, result);
		func_ov000_02159eac(obj->unknown_10_, &local, 0x21);
		void* entry = func_ov024_021e8ca0((struct Struct_ov024_021e2bd0*)obj, code);
		if (entry) {
			func_ov000_0215cd44(obj->unknown_10_, entry, c, 0, 0, 0, 0);
		}
	}
	return local.v;
}
