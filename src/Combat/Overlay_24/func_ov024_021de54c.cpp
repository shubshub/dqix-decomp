#include <globaldefs.h>
#include "GameState/GameState.h"

extern "C" int func_02084a64(unsigned char* obj, int id);
extern "C" void PartyMember_RecalculateStats(unsigned char* p, int v);
extern "C" void func_02089494(char* dst, char* buf, char* src);
void ApplyCombatantBuffs(int world, int id);
extern "C" unsigned short func_ov024_021da644(int idx, int a, int b);
extern "C" void* func_ov000_0215e958(void* a0);
extern "C" void func_ov000_0215a88c(void* objRaw, void* arg1, int c);
extern "C" void func_ov000_0215cd44(void* a, void* b, void* c, int d, int e, int f, int g);

struct Struct_ov024_021de54c_2 {
	unsigned int a : 10;
	unsigned int b : 10;
	unsigned int c : 10;
	unsigned int hi : 2;
};

struct Struct_ov024_021de54c_3 { char pad0[0x1c]; unsigned char unknown_1c_0_ : 7; unsigned char flag : 1; };
struct Struct_ov024_021de54c_4 { char pad0[0xc]; struct Struct_ov024_021de54c_3* unknown_c_; void* unknown_10_; int count; };
struct Struct_ov024_021de54c_5 {
	char pad0[4];
	unsigned int itemId : 12;
	unsigned int unknown_5_4_ : 20;
	char pad8[0x18];
	struct Struct_ov024_021de54c_2 f20;
	struct Struct_ov024_021de54c_2 f24;
};
struct Struct_ov024_021de54c {
	char pad0[0x130];
	char* unknown_130_;
	char* baseStats;
	char* currentStats;
#if defined(jpn)
	char unknown_13c_[8];
#else
	char unknown1_13c_[0x14];
#endif

	unsigned char* field0x150;
};

// USA: func_ov024_021de54c
extern "C" ARM void* func_ov024_021de54c(struct Struct_ov024_021de54c_4* obj, int unused, int id, struct Struct_ov024_021de54c_5* params) {
	struct Struct_ov024_021de54c* c = (struct Struct_ov024_021de54c*)func_0200ff1c(GameState::GetInstance(), id);
	if (!c) return 0;
	unsigned short sel;
	if (func_02084a64(c->field0x150, params->itemId) > 0) {
		sel = func_ov024_021da644(id, params->f20.c, params->f24.a);
		PartyMember_RecalculateStats(c->field0x150, 0);
		func_02089494(c->currentStats, c->unknown_130_, c->baseStats);
		ApplyCombatantBuffs((int)obj->unknown_10_, id);
		obj->count++;
	} else {
		sel = func_ov024_021da644(id, params->f24.b, params->f24.c);
	}
	void* entry = func_ov000_0215e958(obj->unknown_10_);
	if (!entry) return 0;
	func_ov000_0215a88c(obj->unknown_10_, entry, sel);
	func_ov000_0215cd44(obj->unknown_10_, entry, c, 0, 0, 0, obj->unknown_c_->flag != 0);
	return entry;
}
