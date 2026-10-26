#include <globaldefs.h>
#include "Combat/Overlay_0/GetCombatantByID.h"
#include "GameState/GameState.h"

extern "C" int func_0208824c(unsigned char* obj);
extern "C" void func_0208826c(unsigned char* obj);
struct Struct_ov024_021ddc80_4;
extern "C" int func_ov024_021e9464(struct Struct_ov024_021ddc80_4* ctx, int id, int mode);
struct Struct_ov024_021da670_6;
extern "C" int func_ov024_021da998(struct Struct_ov024_021da670_6* obj);
extern "C" int func_ov024_021eb4b0(int a0, int flags, int mask);
extern "C" void func_ov000_02159eac(void* a0, void* buf, int a2);
struct Struct_ov024_021ddc80_5;
extern "C" void* func_ov024_021e8cfc(struct Struct_ov024_021ddc80_5* obj, void* c, int kind, int arg3);
extern "C" void* func_ov000_0215e958(void* a0);
extern "C" void func_ov024_021e8bf0(void* work, void* fieldC, unsigned short* sel);
extern "C" void func_ov000_0215a88c(void* objRaw, void* arg1, int c);
extern "C" void func_ov000_0215cd44(void* a, void* b, void* c, int d, unsigned long long arg4, int g);

struct Struct_ov024_021ddc80_6 { unsigned char pad : 7; unsigned char flag : 1; };
struct Struct_ov024_021ddc80 { char pad0[0xc]; void* unknown_c_; void* unknown_10_; int unknown_14_; };
struct Struct_ov024_021ddc80_2 { int unknown_0_; unsigned int id : 12; unsigned int pad4 : 20; };
struct Struct_ov024_021ddc80_3 { char pad[0x14]; int flags; };

// USA: func_ov024_021ddc80
extern "C" ARM void* func_ov024_021ddc80(struct Struct_ov024_021ddc80* obj, int unused, int id, struct Struct_ov024_021ddc80_2* move, int arg4, int arg5, unsigned char arg6) {
	GameObject* c = GetCombatantByID((int)obj->unknown_10_, id);
	if (!c) return 0;
	int mode = 0;
	int clear = func_0208824c((unsigned char*)c->currentStats_);
	if (clear != 0 && arg6 != 0) {
		mode = 1;
	}
	unsigned short sel = func_ov024_021e9464((struct Struct_ov024_021ddc80_4*)obj, id, mode);
	if (move->id == 0x393) {
		sel = 0;
	}
	int notify = func_ov024_021da998((struct Struct_ov024_021da670_6*)c);
	union { struct { int lo; int hi; }; unsigned long long v; } local;
	local.lo = 0;
	local.hi = 0;
	if (mode) {
		if (func_ov024_021eb4b0((int)obj, ((struct Struct_ov024_021ddc80_3*)c->currentStats_)->flags, 8)) {
			func_ov000_02159eac(obj->unknown_10_, &local, 0x2b);
		}
		func_0208826c((unsigned char*)c->currentStats_);
		func_ov000_02159eac(obj->unknown_10_, &local, 0x18);
		obj->unknown_14_++;
		if (notify) {
			func_ov024_021e8cfc((struct Struct_ov024_021ddc80_5*)obj, c, 0, 0);
		}
	}
	void* entry = func_ov000_0215e958(obj->unknown_10_);
	if (!entry) return 0;
	func_ov024_021e8bf0(obj, obj->unknown_c_, &sel);
	if (sel != 0) {
		func_ov000_0215a88c(obj->unknown_10_, entry, sel);
	}
	struct Struct_ov024_021ddc80_6* var7 = (struct Struct_ov024_021ddc80_6*)((char*)obj->unknown_c_ + 0x1c);
	func_ov000_0215cd44(obj->unknown_10_, entry, c, 0, local.v, var7->flag != 0);
	return entry;
}
