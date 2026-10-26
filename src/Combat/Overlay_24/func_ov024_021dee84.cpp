#include <globaldefs.h>
#include "Combat/Overlay_0/GetCombatantByID.h"
#include "GameState/GameState.h"

struct Struct_02087c30;
extern "C" int func_02087c30(Struct_02087c30* p, unsigned char arg1);
struct Struct_02087c84;
extern "C" int func_02087c84(struct Struct_02087c84* p, int delta);
void UpdateCombatantMagicalMending(int unused, int combatantId);
struct Struct_ov024_021dee84_4;
extern "C" unsigned short func_ov024_021e9990(Struct_ov024_021dee84_4* s, int id, int arg2, unsigned char flag, signed char sb);
extern "C" unsigned short func_ov024_021da644(int idx, int a, int b);
extern "C" void* func_ov000_0215e958(void* a0);
extern "C" void func_ov024_021e8bf0(void* work, void* fieldC, unsigned short* sel);
extern "C" void func_ov000_0215a88c(void* objRaw, void* arg1, int c);
extern "C" void func_ov000_0215cd44(void* a, void* b, void* c, int d, int e, int f, int g);

struct Struct_ov024_021dee84_5 {
	unsigned int a : 10;
	unsigned int b : 10;
	unsigned int c : 10;
	unsigned int hi : 2;
};
struct Struct_ov024_021dee84 { unsigned char pad : 7; unsigned char flag : 1; };
struct Struct_ov024_021dee84_2 { char pad0[0xc]; void* unknown_c_; void* unknown_10_; int unknown_14_; };
struct Struct_ov024_021dee84_3 { char pad0[0x24]; struct Struct_ov024_021dee84_5 f24; char pad1[0x8]; short unknown_30_; };

// USA: func_ov024_021dee84
extern "C" ARM void* func_ov024_021dee84(struct Struct_ov024_021dee84_2* obj, int unused, int id, struct Struct_ov024_021dee84_3* action, int arg4, int arg5, unsigned char arg6) {
	GameObject* c = GetCombatantByID((int)obj->unknown_10_, id);
	if (!c) return 0;
	int var1 = 0;
	int result = var1;
	int var3 = var1;
	if (arg6) {
		int stage = action->unknown_30_;
		if (stage < -2) stage = -2;
		if (stage > 2) stage = 2;
		if (stage < 0) var3 = 1;
		if (func_02087c30((struct Struct_02087c30*)c->currentStats_, var3)) {
			result = func_02087c84((struct Struct_02087c84*)c->currentStats_, (signed char)stage);
			UpdateCombatantMagicalMending((int)obj->unknown_10_, id);
			obj->unknown_14_++;
			var1 = 1;
		}
	}
	unsigned short sel = 0;
	if (var1) {
		sel = func_ov024_021e9990((struct Struct_ov024_021dee84_4*)obj, id, (int)action, (unsigned char)var3, result);
	} else {
		sel = func_ov024_021da644(id, action->f24.b, action->f24.c);
	}
	void* entry = func_ov000_0215e958(obj->unknown_10_);
	if (!entry) return 0;
	func_ov024_021e8bf0(obj, obj->unknown_c_, &sel);
	func_ov000_0215a88c(obj->unknown_10_, entry, sel);
	struct Struct_ov024_021dee84* var7 = (struct Struct_ov024_021dee84*)((char*)obj->unknown_c_ + 0x1c);
	func_ov000_0215cd44(obj->unknown_10_, entry, c, 0, 0, 0, var7->flag != 0);
	return entry;
}
