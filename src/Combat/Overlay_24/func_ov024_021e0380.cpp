#include <globaldefs.h>
#include "Combat/Overlay_0/GetCombatantByID.h"
#include "GameState/GameState.h"

struct Struct_02087a48;
struct Struct_02087a9c;
extern "C" int func_02087a48(struct Struct_02087a48* p, int arg1);
extern "C" int func_02087a9c(struct Struct_02087a9c* p, int delta);
void UpdateCombatantCharm(int unused, int combatantId);
extern "C" unsigned short func_ov024_021da644(int idx, int a, int b);
extern "C" void* func_ov000_0215e958(void* a0);
extern "C" void func_ov024_021e8bf0(void* work, void* fieldC, unsigned short* sel);
extern "C" void func_ov000_0215a88c(void* objRaw, void* arg1, int c);
extern "C" void func_ov000_0215cd44(void* a, void* b, void* c, int d, int e, int f, int g);

struct Struct_ov024_021e0380_2 {
    unsigned int a : 10;
    unsigned int b : 10;
    unsigned int c : 10;
    unsigned int hi : 2;
};
struct Struct_ov024_021e0380_3 { unsigned char pad : 7; unsigned char flag : 1; };
struct Struct_ov024_021e0380_4 { char pad0[0xc]; void* unknown_c_; void* unknown_10_; };
struct Struct_ov024_021e0380 { char pad[0x24]; struct Struct_ov024_021e0380_2 f24; char pad28[0x8]; short unknown_30_; };

// USA: func_ov024_021e0380
extern "C" ARM void* func_ov024_021e0380(struct Struct_ov024_021e0380_4* obj, int unused, int id, struct Struct_ov024_021e0380* range, int arg4, int arg5, unsigned char arg6) {
	GameObject* c = GetCombatantByID((int)obj->unknown_10_, id);
	if (!c) return 0;
	int var1 = 0;
	int stage = 0;
	if (arg6 != 0) {
		int delta = range->unknown_30_;
		if (delta < -2) delta = -2;
		if (delta > 2) delta = 2;
		int var4 = 0;
		if (delta < 0) var4 = 1;
		if (func_02087a48((struct Struct_02087a48*)c->currentStats_, (unsigned char)var4)) {
			stage = func_02087a9c((struct Struct_02087a9c*)c->currentStats_, (signed char)delta);
			UpdateCombatantCharm((int)obj->unknown_10_, id);
			var1 = 1;
		}
	}
	unsigned short sel = 0;
	if (var1) {
		if (range->unknown_30_ > 0 && stage == 2) sel = 0xf7;
	} else {
		sel = func_ov024_021da644(id, range->f24.b, range->f24.c);
	}
	void* entry = func_ov000_0215e958(obj->unknown_10_);
	if (!entry) return 0;
	func_ov024_021e8bf0(obj, obj->unknown_c_, &sel);
	func_ov000_0215a88c(obj->unknown_10_, entry, sel);
	struct Struct_ov024_021e0380_3* var7 = (struct Struct_ov024_021e0380_3*)((char*)obj->unknown_c_ + 0x1c);
	func_ov000_0215cd44(obj->unknown_10_, entry, c, 0, 0, 0, var7->flag != 0);
	return entry;
}
