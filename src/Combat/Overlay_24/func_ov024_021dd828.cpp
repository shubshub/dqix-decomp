#include <globaldefs.h>
#include "Combat/Overlay_0/GetCombatantByID.h"
#include "GameState/GameState.h"

extern "C" int func_020883ac(unsigned char* obj);
struct Struct_ov024_021dd828;
extern "C" int func_ov024_021e9320(struct Struct_ov024_021dd828* ctx, int id, int mode);
extern "C" int func_ov024_021eb4b0(int a0, int flags, int mask);
extern "C" void func_ov000_02159eac(void* a0, void* buf, int a2);
extern "C" void func_020883cc(unsigned char* obj);
extern "C" void* func_ov000_0215e958(void* a0);
extern "C" void func_ov024_021e8bf0(void* work, void* fieldC, unsigned short* sel);
extern "C" void func_ov000_0215a88c(void* objRaw, void* arg1, int c);
extern "C" void func_ov000_0215cd44(void* a, void* b, void* c, int d, unsigned long long arg4, int g);

struct Struct_ov024_021dd828_2 { unsigned char pad : 7; unsigned char flag : 1; };
struct Struct_ov024_021dd828_3 { char pad[0x14]; int flags; };
struct Struct_ov024_021dd828_4 { char pad0[0xc]; void* unknown_c_; void* unknown_10_; int unknown_14_; char pad18[0x75 - 0x18]; unsigned char unknown_75_; };

// USA: func_ov024_021dd828
extern "C" ARM void* func_ov024_021dd828(struct Struct_ov024_021dd828_4* obj, int unused, int id, int unused1, int arg4, int arg5, unsigned char arg6) {
	GameObject* c = GetCombatantByID((int)obj->unknown_10_, id);
	if (!c) return 0;
	int active = 0;
	if (func_020883ac((unsigned char*)c->currentStats_) && arg6) {
		active = 1;
	} else {
		obj->unknown_75_ = 0;
	}
	unsigned short sel = func_ov024_021e9320((struct Struct_ov024_021dd828*)obj, id, active);
	union { struct { int lo; int hi; }; unsigned long long v; } local;
	local.lo = 0;
	local.hi = 0;
	if (active) {
		if (func_ov024_021eb4b0((int)obj, ((struct Struct_ov024_021dd828_3*)c->currentStats_)->flags, 0x20)) {
			func_ov000_02159eac(obj->unknown_10_, &local, 0x2b);
		}
		func_020883cc((unsigned char*)c->currentStats_);
		func_ov000_02159eac(obj->unknown_10_, &local, 0x17);
		obj->unknown_14_++;
	}
	void* entry = func_ov000_0215e958(obj->unknown_10_);
	if (!entry) return 0;
	func_ov024_021e8bf0(obj, obj->unknown_c_, &sel);
	func_ov000_0215a88c(obj->unknown_10_, entry, sel);
	struct Struct_ov024_021dd828_2* var5 = (struct Struct_ov024_021dd828_2*)((char*)obj->unknown_c_ + 0x1c);
	func_ov000_0215cd44(obj->unknown_10_, entry, c, 0, local.v, var5->flag != 0);
	return entry;
}
