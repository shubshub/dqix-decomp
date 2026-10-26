#include <globaldefs.h>
#include "Combat/Overlay_0/GetCombatantByID.h"
#include "GameState/GameState.h"

struct Struct_02088018;
struct Struct_0208806c;
extern "C" int func_02088018(struct Struct_02088018* p, int arg1);
extern "C" int func_0208806c(struct Struct_0208806c* p, int delta);
extern "C" unsigned short func_ov024_021da644(int idx, int a, int b);
extern "C" void* func_ov000_0215e958(void* a0);
extern "C" void func_ov000_0215a88c(void* objRaw, void* arg1, int c);
extern "C" void func_ov000_0215cd44(void* a, void* b, void* c, int d, int e, int f, int g);

struct Struct_ov024_021ded48 {
	unsigned int a : 10;
	unsigned int b : 10;
	unsigned int c : 10;
	unsigned int hi : 2;
};

struct Struct_ov024_021ded48_2 { unsigned char pad : 7; unsigned char flag : 1; };
struct Struct_ov024_021ded48_3 { char pad0[0xc]; void* unknown_c_; void* unknown_10_; };
struct Struct_ov024_021ded48_4 {
	char pad[0x20];
	struct Struct_ov024_021ded48 f20;
	struct Struct_ov024_021ded48 f24;
	char pad28[0x8];
	short unknown_30_;
};

// USA: func_ov024_021ded48
extern "C" ARM void* func_ov024_021ded48(struct Struct_ov024_021ded48_3* obj, int unused, int id, struct Struct_ov024_021ded48_4* range, int arg4, int arg5, unsigned char arg6) {
	GameObject* c = GetCombatantByID((int)obj->unknown_10_, id);
	if (!c) return 0;
	int var1 = 0;
	if (arg6 != 0) {
		int stage = range->unknown_30_;
		if (stage < -2) stage = -2;
		if (stage > 2) stage = 2;
		int var3 = 0;
		if (stage < 0) var3 = 1;
		if (func_02088018((struct Struct_02088018*)c->currentStats_, (unsigned char)var3)) {
			func_0208806c((struct Struct_0208806c*)c->currentStats_, (signed char)stage);
			var1 = 1;
		}
	}
	unsigned short sel;
	if (var1) {
		sel = func_ov024_021da644(id, range->f20.c, range->f24.a);
	} else {
		sel = func_ov024_021da644(id, range->f24.b, range->f24.c);
	}
	void* entry = func_ov000_0215e958(obj->unknown_10_);
	if (!entry) return 0;
	func_ov000_0215a88c(obj->unknown_10_, entry, sel);
	struct Struct_ov024_021ded48_2* var6 = (struct Struct_ov024_021ded48_2*)((char*)obj->unknown_c_ + 0x1c);
	func_ov000_0215cd44(obj->unknown_10_, entry, c, 0, 0, 0, var6->flag != 0);
	return entry;
}
