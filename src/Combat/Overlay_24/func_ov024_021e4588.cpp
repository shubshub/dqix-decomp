#include <globaldefs.h>
#include "Combat/Overlay_0/GetCombatantByID.h"
#include "GameState/GameState.h"

struct Struct_ov024_021de124;
extern "C" int func_ov024_021de25c(struct Struct_ov024_021de124* obj);
extern "C" void func_020883fc(void* obj);
extern "C" void func_ov000_02159eac(void* a0, void* buf, int a2);

struct Struct_ov024_021e4588 { char pad[0x10]; void* unknown_10_; };
struct Struct_ov024_021e4588_2 { char pad[0x3b]; unsigned char b; };

// USA: func_ov024_021e4588
extern "C" ARM unsigned long long func_ov024_021e4588(struct Struct_ov024_021e4588* obj, int unused, int id) {
	GameObject* c = GetCombatantByID((int)obj->unknown_10_, id);
	if (!c) return 0;
	union { struct { int lo; int hi; }; unsigned long long v; } local;
	local.lo = 0;
	local.hi = 0;
	if (func_ov024_021de25c((struct Struct_ov024_021de124*)c)) {
		func_020883fc(c->currentStats_);
		struct Struct_ov024_021e4588_2* s = (struct Struct_ov024_021e4588_2*)c->currentStats_;
		s->b = (s->b & ~1) | 1;
		func_ov000_02159eac(obj->unknown_10_, &local, 0x19);
	}
	return local.v;
}
