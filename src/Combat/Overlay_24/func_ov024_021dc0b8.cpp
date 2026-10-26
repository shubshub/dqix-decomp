#include <globaldefs.h>
#include "Combat/Overlay_0/GetCombatantByID.h"
#include "GameState/GameState.h"

struct ArrayContainsByteStruct;
extern "C" int func_02086ef0(ArrayContainsByteStruct* s, int val);
extern "C" void* GameState_GetParty(GameState* gameState);
extern "C" unsigned short func_ov024_021da644(int idx, int a, int b);
extern "C" void func_ov000_0215a8d4(unsigned char* battle, int idx);
extern "C" void* func_ov000_0215e958(void* a0);
extern "C" void func_ov000_0215a88c(void* objRaw, void* arg1, int c);
extern "C" void func_ov000_0215cd44(void* a, void* b, void* c, int d, unsigned long long arg4, int g);

struct Struct_ov024_021dc0b8_3 {
	unsigned int a : 10;
	unsigned int b : 10;
	unsigned int c : 10;
	unsigned int hi : 2;
};

struct Struct_ov024_021dc0b8_4 {
	char pad0[4];
	unsigned int unknown_4_0_ : 12;
	unsigned int unknown_5_4_ : 20;
	char pad8[0x20 - 0x8];
	struct Struct_ov024_021dc0b8_3 f20;
	struct Struct_ov024_021dc0b8_3 f24;
	char pad28[0x32 - 0x28];
	short unknown_32_;
};

struct Struct_ov024_021dc0b8 { unsigned char pad : 7; unsigned char flag : 1; };
struct Struct_ov024_021dc0b8_2 { char pad0[0xc]; char* unknown_c_; void* unknown_10_; int unknown_14_; };

extern "C" unsigned long long func_ov024_021e4b14(struct Struct_ov024_021dc0b8_2* self, int a, int b, struct Struct_ov024_021dc0b8_4* rec, int d);
extern "C" unsigned short func_ov024_021e9018(struct Struct_ov024_021dc0b8_2* obj, int id, int value, int mode);
extern "C" void func_ov024_021e8bf0(void* work, void* fieldC, unsigned short* sel);

// USA: func_ov024_021dc0b8
extern "C" ARM void* func_ov024_021dc0b8(struct Struct_ov024_021dc0b8_2* obj, int target, int id, struct Struct_ov024_021dc0b8_4* params, int unused4, int arg5, unsigned char arg6) {
	GameObject* c = GetCombatantByID((int)obj->unknown_10_, id);
	if (!c) return 0;
	unsigned short sel = 0;
	unsigned long long var2 = 0;
	int flag = ((struct Struct_ov024_021dc0b8*)(obj->unknown_c_ + 0x1c))->flag != 0;
	int handled = 0;
	if (arg6 != 0) {
		var2 = func_ov024_021e4b14(obj, target, id, params, 1);
		if (var2 != 0) {
			sel = func_ov024_021da644(id, params->f20.c, params->f24.a);
			void* list = GameState_GetParty(GameState::GetInstance());
			if (flag && func_02086ef0((ArrayContainsByteStruct*)list, target) && params->unknown_4_0_ == 0xa9) {
				func_ov000_0215a8d4((unsigned char*)obj->unknown_10_, 5);
			}
			obj->unknown_14_++;
			handled = 1;
		}
	}
	if (!handled) {
		sel = func_ov024_021e9018(obj, id, params->unknown_32_, 0);
		if (sel == 0) {
			sel = func_ov024_021da644(id, params->f24.b, params->f24.c);
		}
	}
	if (params->unknown_4_0_ == 0x20f) sel = 0;
	void* entry = func_ov000_0215e958(obj->unknown_10_);
	if (!entry) return 0;
	func_ov024_021e8bf0(obj, obj->unknown_c_, &sel);
	func_ov000_0215a88c(obj->unknown_10_, entry, sel);
	struct Struct_ov024_021dc0b8* var7 = (struct Struct_ov024_021dc0b8*)(obj->unknown_c_ + 0x1c);
	func_ov000_0215cd44(obj->unknown_10_, entry, c, 0, var2, var7->flag != 0);
	return entry;
}
