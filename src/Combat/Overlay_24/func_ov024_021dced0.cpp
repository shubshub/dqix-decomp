#include <globaldefs.h>
#include "Combat/Overlay_0/GetCombatantByID.h"
#include "GameState/GameState.h"

extern "C" int func_02088890(unsigned char* obj);
struct Struct_ov024_021dced0_2;
extern "C" int func_ov024_021dd010(struct Struct_ov024_021dced0_2* obj);
extern "C" unsigned short func_ov024_021da644(int idx, int a, int b);
extern "C" void func_020888a4(unsigned char* obj);
extern "C" void* func_ov000_0215e958(void* a0);
extern "C" void func_ov024_021e8bf0(void* work, void* fieldC, unsigned short* sel);
extern "C" void func_ov000_0215a88c(void* objRaw, void* arg1, int c);
extern "C" void func_ov000_0215cd44(void* a, void* b, void* c, int d, int e, int f, int g);

struct Struct_ov024_021dced0_3 {
    unsigned int a : 10;
    unsigned int b : 10;
    unsigned int c : 10;
    unsigned int hi : 2;
};
struct Struct_ov024_021dced0_4 { unsigned char pad : 7; unsigned char flag : 1; };
struct Struct_ov024_021dced0_5 { char pad0[0xc]; void* unknown_c_; void* unknown_10_; char unknown_14_[0x75 - 0x14]; unsigned char unknown_75_; };
struct Struct_ov024_021dced0 { char pad[0x20]; struct Struct_ov024_021dced0_3 f20; struct Struct_ov024_021dced0_3 f24; };

// USA: func_ov024_021dced0
extern "C" ARM void* func_ov024_021dced0(struct Struct_ov024_021dced0_5* obj, int unused, int id, struct Struct_ov024_021dced0* range, int arg4, int arg5, unsigned char arg6) {
	GameObject* c = GetCombatantByID((int)obj->unknown_10_, id);
	if (!c) return 0;
	unsigned short sel = 0;
	if (func_02088890((unsigned char*)c->currentStats_) && arg6) {
		if (func_ov024_021dd010((struct Struct_ov024_021dced0_2*)c)) {
			sel = func_ov024_021da644(id, 0x19, 0x1a);
		} else {
			sel = func_ov024_021da644(id, range->f20.c, range->f24.a);
		}
		func_020888a4((unsigned char*)c->currentStats_);
	} else {
		sel = func_ov024_021da644(id, range->f24.b, range->f24.c);
		obj->unknown_75_ = 0;
	}
	void* entry = func_ov000_0215e958(obj->unknown_10_);
	if (!entry) return 0;
	func_ov024_021e8bf0(obj, obj->unknown_c_, &sel);
	func_ov000_0215a88c(obj->unknown_10_, entry, sel);
	struct Struct_ov024_021dced0_4* var3 = (struct Struct_ov024_021dced0_4*)((char*)obj->unknown_c_ + 0x1c);
	func_ov000_0215cd44(obj->unknown_10_, entry, c, 0, 0, 0, var3->flag != 0);
	return entry;
}
