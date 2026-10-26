#include <globaldefs.h>
#include "Combat/Overlay_0/GetCombatantByID.h"
#include "GameState/GameState.h"

struct Struct_02087954;
extern "C" int func_02087954(struct Struct_02087954* p, int arg1);
extern "C" int func_020879a8(void* p, signed char delta);
void UpdateCombatantAgility(int unused, int id);
extern "C" int func_ov024_021e96e4(void* ctx, int id, void* params, unsigned char mode, signed char result, unsigned char arg5, unsigned char arg6);
extern "C" void func_ov000_02159eac(void* a0, void* buf, int a2);
struct Struct_ov024_021e2bd0;
extern "C" void* func_ov024_021e8ca0(struct Struct_ov024_021e2bd0* obj, int id);
extern "C" void func_ov000_0215cd44(void* a, void* b, void* c, int d, unsigned long long arg4, int g);

struct Struct_ov024_021e42b8 { char pad0[0x10]; void* unknown_10_; };
struct Struct_ov024_021e42b8_2 { char pad0[0x32]; short unknown_32_; };

// USA: func_ov024_021e42b8
extern "C" ARM unsigned long long func_ov024_021e42b8(struct Struct_ov024_021e42b8* obj, int unused, int id, struct Struct_ov024_021e42b8_2* params) {
	GameObject* c = GetCombatantByID((int)obj->unknown_10_, id);
	if (!c) return 0;
	int delta = params->unknown_32_;
	if (delta < -2) delta = -2;
	if (delta > 2) delta = 2;
	int var2 = 0;
	if (delta < 0) var2 = 1;
	int changed = 0;
	int var4 = 0;
	if (func_02087954((struct Struct_02087954*)c->currentStats_, (unsigned char)var2)) {
		var4 = func_020879a8(c->currentStats_, delta);
		UpdateCombatantAgility((int)obj->unknown_10_, id);
		changed = 1;
	}
	union { struct { int lo; int hi; }; unsigned long long v; } local;
	local.lo = 0;
	local.hi = 0;
	if (changed) {
		int msg = func_ov024_021e96e4(obj, id, params, var2, var4, 1, 1);
		func_ov000_02159eac(obj->unknown_10_, &local, 0x1f);
		void* entry = func_ov024_021e8ca0((struct Struct_ov024_021e2bd0*)obj, msg);
		if (entry) {
			func_ov000_0215cd44(obj->unknown_10_, entry, c, 0, 0, 0);
		}
	}
	return local.v;
}
