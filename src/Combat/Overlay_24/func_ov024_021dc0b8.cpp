#include <globaldefs.h>
#include "Combat/Overlay_0/GetCombatantByID.h"
#include "GameState/GameState.h"

struct ArrayContainsByteStruct;
int ArrayContainsByte_02086ef0(ArrayContainsByteStruct* s, int val);
void* GameState_GetParty(GameState* gameState);
unsigned short SelectByIndexRange0to3_021da644(int idx, int a, int b);
void IncrementByteCounterCapped0x63_0215a8d4(unsigned char* battle, int idx);
extern "C" void* func_ov000_0215e958(void* a0);
void AddEntryAndIncrementCount0215a88c(void* objRaw, void* listRaw, int c);
extern "C" void func_ov000_0215cd44(void* a, void* b, void* c, int d, unsigned long long ef, int g);

struct Struct_ov024_021dc0b8_3 {
	unsigned int unknown_0_0_ : 10;
	unsigned int unknown_1_2_ : 10;
	unsigned int unknown_2_4_ : 10;
	unsigned int unknown_3_6_ : 2;
};

struct Struct_ov024_021dc0b8_4 {
	char unknown_0_[4];
	unsigned int unknown_4_0_ : 12;
	unsigned int unknown_5_4_ : 20;
	char unknown_8_[0x20 - 0x8];
	struct Struct_ov024_021dc0b8_3 unknown_20_;
	struct Struct_ov024_021dc0b8_3 unknown_24_;
	char unknown_28_[0x32 - 0x28];
	short unknown_32_;
};

struct Struct_ov024_021dc0b8 { unsigned char unknown_0_0_ : 7; unsigned char unknown_0_7_ : 1; };
struct Struct_ov024_021dc0b8_2 { char unknown_0_[0xc]; char* unknown_c_; void* unknown_10_; int unknown_14_; };

extern "C" unsigned long long func_ov024_021e4b14(struct Struct_ov024_021dc0b8_2* arg0, int arg1, int arg2, struct Struct_ov024_021dc0b8_4* arg3, int arg4);
extern "C" unsigned short func_ov024_021e9018(struct Struct_ov024_021dc0b8_2* arg0, int arg1, int arg2, int arg3);
extern "C" void func_ov024_021e8bf0(void* arg0, void* arg1, unsigned short* arg2);

// USA: func_ov024_021dc0b8
extern "C" ARM void* func_ov024_021dc0b8(struct Obj_021dc0b8* obj, int target, int id, struct Params_021dc0b8* params, int unused4, int unused5, unsigned char flagArg) {
	GameObject* c = GetCombatantByID((int)obj->field0x10, id);
	if (!c) return 0;
	unsigned short sel = 0;
	unsigned long long ef = 0;
	int flag = ((struct Flag_021dc0b8*)(obj->field0xc + 0x1c))->flag != 0;
	int handled = 0;
	if (flagArg != 0) {
		ef = func_ov024_021e4b14(obj, target, id, params, 1);
		if (ef != 0) {
			sel = SelectByIndexRange0to3_021da644(id, params->f20.c, params->f24.a);
			void* list = GameState_GetParty(GameState::GetInstance());
			if (flag && ArrayContainsByte_02086ef0((ArrayContainsByteStruct*)list, target) && params->actionId == 0xa9) {
				IncrementByteCounterCapped0x63_0215a8d4((unsigned char*)obj->field0x10, 5);
			}
			arg0->unknown_14_++;
			var4 = 1;
		}
	}
	if (!var4) {
		var1 = func_ov024_021e9018(arg0, arg2, arg3->unknown_32_, 0);
		if (var1 == 0) {
			var1 = func_ov024_021da644(arg2, arg3->unknown_24_.unknown_1_2_, arg3->unknown_24_.unknown_2_4_);
		}
	}
	if (arg3->unknown_4_0_ == 0x20f) var1 = 0;
	void* var6 = func_ov000_0215e958(arg0->unknown_10_);
	if (!var6) return 0;
	func_ov024_021e8bf0(arg0, arg0->unknown_c_, &var1);
	func_ov000_0215a88c(arg0->unknown_10_, var6, var1);
	struct Struct_ov024_021dc0b8* var7 = (struct Struct_ov024_021dc0b8*)(arg0->unknown_c_ + 0x1c);
	func_ov000_0215cd44(arg0->unknown_10_, var6, var0, 0, var2, var7->unknown_0_7_ != 0);
	return var6;
}
