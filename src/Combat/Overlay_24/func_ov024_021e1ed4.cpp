#include <globaldefs.h>
#include "Combat/Overlay_0/GetCombatantByID.h"
#include "GameState/GameState.h"

struct Struct_02087860;
struct Struct_02087e18;
struct Struct_02087e6c;
extern "C" int func_02087860(Struct_02087860* p, unsigned char arg1);
extern "C" int func_020878b4(void* stats, int delta);
extern "C" int func_02087e18(Struct_02087e18* p, unsigned char arg1);
extern "C" int func_02087e6c(Struct_02087e6c* obj, int delta);
extern "C" int func_0208776c(void* stats, int dir);
extern "C" int func_020877c0(void* stats, int delta);
void UpdateCombatantDefense(int random, int combatantId);
void UpdateCombatantAttack(int random, int combatantId);
extern "C" void* func_ov000_0215e958(void* a0);
extern "C" void func_ov000_0215a88c(void* objRaw, void* arg1, int c);
extern "C" void func_ov000_0215cd44(void* a, void* b, void* c, int d, int e, int f, int g);

struct Struct_ov024_021e1ed4_3 {
	char pad[0x24];
	unsigned int a : 10;
	unsigned int b : 10;
	unsigned int c : 10;
	unsigned int hi : 2;
};

struct Struct_ov024_021e1ed4 { unsigned char pad : 7; unsigned char flag : 1; };
struct Struct_ov024_021e1ed4_2 { char pad0[0xc]; void* unknown_c_; void* unknown_10_; };

extern "C" int func_ov024_021e95d4(struct Struct_ov024_021e1ed4_2* ctx, int id, struct Struct_ov024_021e1ed4_3* params, int mode, signed char arg4, unsigned char changed, unsigned char flag);
extern "C" int func_ov024_021e94c4(struct Struct_ov024_021e1ed4_2* ctx, int id, struct Struct_ov024_021e1ed4_3* params, int mode, signed char value, unsigned char arg5, unsigned char arg6);

// USA: func_ov024_021e1ed4
extern "C" ARM void* func_ov024_021e1ed4(struct Struct_ov024_021e1ed4_2* obj, int unused, int id, struct Struct_ov024_021e1ed4_3* params) {
	GameObject* c = GetCombatantByID((int)obj->unknown_10_, id);
	if (!c) return 0;
	void* entry = func_ov000_0215e958(obj->unknown_10_);
	if (!entry) return 0;
	int changed = 0;
	if (func_02087860((Struct_02087860*)c->currentStats_, 0)) {
		changed = 1;
		int delta = func_020878b4(c->currentStats_, 1);
		UpdateCombatantDefense((int)obj->unknown_10_, id);
		func_ov000_0215a88c(obj->unknown_10_, entry, func_ov024_021e95d4(obj, id, params, 0, delta, 1, 1));
	}
	if (func_02087e18((Struct_02087e18*)c->currentStats_, 0)) {
		changed = 1;
		int result = func_02087e6c((Struct_02087e6c*)c->currentStats_, 1);
		int msg;
		switch (result) {
			case 2: msg = 0x1b0; break;
			case 0: msg = 0x1af; break;
			default: msg = 0x1b1; break;
		}
		func_ov000_0215a88c(obj->unknown_10_, entry, msg);
	}
	if (func_0208776c(c->currentStats_, 0)) {
		changed = 1;
		int delta = func_020877c0(c->currentStats_, 1);
		UpdateCombatantAttack((int)obj->unknown_10_, id);
		func_ov000_0215a88c(obj->unknown_10_, entry, func_ov024_021e94c4(obj, id, params, 0, delta, 1, 1));
	}
	if (!changed) {
		func_ov000_0215a88c(obj->unknown_10_, entry, (unsigned short)params->b);
	}
	struct Struct_ov024_021e1ed4* var7 = (struct Struct_ov024_021e1ed4*)((char*)obj->unknown_c_ + 0x1c);
	func_ov000_0215cd44(obj->unknown_10_, entry, c, 0, 0, 0, var7->flag != 0);
	return entry;
}
