#include <globaldefs.h>
#include "GameState/GameState.h"

extern "C" int func_02084a64(unsigned char* obj, int id);
extern "C" void PartyMember_RecalculateStats(unsigned char* p, int v);
void CopyPackedFields02089494(char* dst, char* buf, char* src);
void ApplyCombatantBuffs(int world, int id);
extern "C" unsigned short func_ov024_021da644(int arg0, int arg1, int arg2);
extern "C" void* func_ov000_0215e958(void* arg0);
extern "C" void func_ov000_0215a88c(void* arg0, void* arg1, int arg2);
extern "C" void func_ov000_0215cd44(void* arg0, void* arg1, void* arg2, int arg3, int arg4, int arg5, int arg6);

struct Struct_ov024_021de54c_2 {
	unsigned int unknown_0_0_ : 10;
	unsigned int unknown_1_2_ : 10;
	unsigned int unknown_2_4_ : 10;
	unsigned int unknown_3_6_ : 2;
};

struct Struct_ov024_021de54c_3 { char unknown_0_[0x1c]; unsigned char unknown_1c_0_ : 7; unsigned char unknown_1c_7_ : 1; };
struct Struct_ov024_021de54c_4 { char unknown_0_[0xc]; struct Struct_ov024_021de54c_3* unknown_c_; void* unknown_10_; int unknown_14_; };
struct Struct_ov024_021de54c_5 {
	char unknown_0_[4];
	unsigned int unknown_4_0_ : 12;
	unsigned int unknown_5_4_ : 20;
	char unknown_8_[0x18];
	struct Struct_ov024_021de54c_2 unknown_20_;
	struct Struct_ov024_021de54c_2 unknown_24_;
};
struct Struct_ov024_021de54c {
	char unknown_0_[0x130];
	char* unknown_130_;
	char* unknown_134_;
	char* unknown_138_;
#if defined(jpn)
	char unknown_13c_[8];
#else
	char unknown1_13c_[0x14];
#endif

	unsigned char* unknown_150_;
};

// USA: func_ov024_021de54c
extern "C" ARM void* func_ov024_021de54c(struct Obj_021de54c* obj, int unused, int id, struct Params_021de54c* params) {
	struct Combatant_021de54c* c = (struct Combatant_021de54c*)GetCombatantWithFlag0x100_0200ff1c(GameState::GetInstance(), id);
	if (!c) return 0;
	unsigned short sel;
	if (func_02084a64(c->field0x150, params->itemId) > 0) {
		sel = SelectByIndexRange0to3_021da644(id, params->f20.c, params->f24.a);
		PartyMember_RecalculateStats(c->field0x150, 0);
		CopyPackedFields02089494(c->currentStats, c->field0x130, c->baseStats);
		ApplyCombatantBuffs((int)obj->field0x10, id);
		obj->count++;
	} else {
		var1 = func_ov024_021da644(arg2, arg3->unknown_24_.unknown_1_2_, arg3->unknown_24_.unknown_2_4_);
	}
	void* var2 = func_ov000_0215e958(arg0->unknown_10_);
	if (!var2) return 0;
	func_ov000_0215a88c(arg0->unknown_10_, var2, var1);
	func_ov000_0215cd44(arg0->unknown_10_, var2, var0, 0, 0, 0, arg0->unknown_c_->unknown_1c_7_ != 0);
	return var2;
}
