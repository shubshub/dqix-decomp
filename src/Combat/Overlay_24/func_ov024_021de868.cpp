#include <globaldefs.h>
#include "Combat/Overlay_0/GetCombatantByID.h"
#include "Combat/Main/BattleList.h"
#include "GameState/GameState.h"

struct S_10088;
extern "C" int func_02010088(struct S_10088* obj);
extern "C" void func_0208902c(unsigned char* obj, int val);
extern "C" void func_ov000_02159eac(void* a0, void* buf, int a2);
extern "C" float func_ov024_021db358(GameObject* obj);
extern "C" short func_ov000_0215a16c(void* unused, int id, int delta, short* arg3);
extern "C" void* func_ov000_0215e958(void* a0);
extern "C" void func_ov000_0215a88c(void* objRaw, void* arg1, int c);
extern "C" void func_ov000_0215cd44(void* a, void* b, void* c, int d, unsigned long long arg4, int g);

struct Struct_ov024_021de868 { unsigned char pad : 7; unsigned char flag : 1; };
struct Struct_ov024_021de868_2 { char pad0[0xc]; void* unknown_c_; void* unknown_10_; };
struct Struct_ov024_021de868_3 {
	char pad0[0x3a];
	unsigned char unknown_3a_;
	unsigned char bit0 : 1;
	unsigned char rest : 7;
};

// USA: func_ov024_021de868
extern "C" ARM void* func_ov024_021de868(struct Struct_ov024_021de868_2* obj, int unused, int id) {
	GameObject* c = GetCombatantByID((int)obj->unknown_10_, id);
	if (!c) return 0;
	short var1 = 0;
	union { struct { int lo; int hi; }; unsigned long long v; } local;
	local.lo = 0;
	local.hi = 0;
	int msg;
	if (func_02010088((struct S_10088*)c)) {
		func_0208902c((unsigned char*)c->currentStats_, c->currentStats_->primaryStats.maxHP);
		func_ov000_02159eac(obj->unknown_10_, &local, 3);
		((struct Struct_ov024_021de868_3*)c->currentStats_)->bit0 = 1;
		msg = 0x20;
		int inRange = (id >= 0 && id <= 3);
		if (inRange) {
			GameObject* member = func_0200ff1c(GameState::GetInstance(), id);
			if (member) {
				((struct Struct_ov024_021de868_3*)member->currentStats_)->unknown_3a_ = 1;
			}
		}
	} else if (func_ov024_021db358(c) < 1.0f) {
		func_ov000_0215a16c(obj->unknown_10_, id, c->currentStats_->primaryStats.maxHP, &var1);
		func_ov000_02159eac(obj->unknown_10_, &local, 0x25);
		msg = 0x16;
	} else {
		msg = 0x1f;
	}
	void* entry = func_ov000_0215e958(obj->unknown_10_);
	if (!entry) return 0;
	func_ov000_0215a88c(obj->unknown_10_, entry, msg);
	struct Struct_ov024_021de868* var7 = (struct Struct_ov024_021de868*)((char*)obj->unknown_c_ + 0x1c);
	func_ov000_0215cd44(obj->unknown_10_, entry, c, (short)-var1, local.v, var7->flag != 0);
	return entry;
}
