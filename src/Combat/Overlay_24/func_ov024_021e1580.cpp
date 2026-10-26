#include <globaldefs.h>
#include "Combat/Overlay_0/GetCombatantByID.h"
#include "GameState/GameState.h"

extern "C" int func_020890c0(unsigned char* obj);
extern "C" void func_020890d4(unsigned char* obj);
extern "C" unsigned short func_ov024_021da644(int idx, int a, int b);
extern "C" void* func_ov000_0215e958(void* a0);
extern "C" void func_ov000_0215a88c(void* objRaw, void* arg1, int c);
extern "C" void func_ov000_0215cd44(void* a, void* b, void* c, int d, int e, int f, int g);

struct Struct_ov024_021e1580 {
    unsigned int a : 10;
    unsigned int b : 10;
    unsigned int c : 10;
    unsigned int hi : 2;
};
struct Struct_ov024_021e1580_2 { unsigned char pad : 7; unsigned char flag : 1; };
struct Struct_ov024_021e1580_3 { char pad0[0xc]; void* unknown_c_; void* unknown_10_; char pad2[0x6e - 0x14]; unsigned char unknown_6e_; };
struct Struct_ov024_021e1580_4 { unsigned int unknown_0_0_ : 12; unsigned int rest : 20; };
struct Struct_ov024_021e1580_5 {
    char pad0[4];
    struct Struct_ov024_021e1580_4 field4;
    char pad1[0x20 - 8];
    struct Struct_ov024_021e1580 f20;
    struct Struct_ov024_021e1580 f24;
};

// USA: func_ov024_021e1580
extern "C" ARM void* func_ov024_021e1580(struct Struct_ov024_021e1580_3* obj, int unused, int id, struct Struct_ov024_021e1580_5* range, int arg4, int arg5, unsigned char arg6) {
	GameObject* c = GetCombatantByID((int)obj->unknown_10_, id);
	if (!c) return 0;
	int clear = func_020890c0((unsigned char*)c->currentStats_);
	unsigned short sel;
	if (clear != 0 && arg6 != 0) {
		func_020890d4((unsigned char*)c->currentStats_);
		sel = func_ov024_021da644(id, range->f20.c, range->f24.a);
	} else {
		sel = func_ov024_021da644(id, range->f24.b, range->f24.c);
	}
	void* entry = func_ov000_0215e958(obj->unknown_10_);
	if (!entry) return 0;
	int extracted = range->field4.unknown_0_0_;
	if (extracted == 0x1fb || obj->unknown_6e_ == 0) {
		func_ov000_0215a88c(obj->unknown_10_, entry, sel);
		obj->unknown_6e_ = 1;
	}
	struct Struct_ov024_021e1580_2* var5 = (struct Struct_ov024_021e1580_2*)((char*)obj->unknown_c_ + 0x1c);
	func_ov000_0215cd44(obj->unknown_10_, entry, c, 0, 0, 0, var5->flag != 0);
	return entry;
}
