#include <globaldefs.h>
#include "Combat/Overlay_0/GetCombatantByID.h"
#include "GameState/GameState.h"

extern "C" int func_02088980(unsigned char* obj);
extern "C" void func_02088994(unsigned char* obj);
extern "C" void func_ov000_02159eac(void* a0, void* buf, int a2);
extern "C" unsigned short func_ov024_021da644(int idx, int a, int b);
extern "C" void* func_ov000_0215e958(void* a0);
extern "C" void func_ov000_0215a88c(void* objRaw, void* arg1, int c);
struct Struct_ov024_021e093c { int lo; int hi; };
extern "C" void func_ov000_0215cd44(void* a, void* b, void* c, int d, struct Struct_ov024_021e093c p, int g);

struct Struct_ov024_021e093c_2 {
	unsigned int a : 10;
	unsigned int b : 10;
	unsigned int c : 10;
	unsigned int hi : 2;
};

struct Struct_ov024_021e093c_3 { unsigned char pad : 7; unsigned char flag : 1; };
struct Struct_ov024_021e093c_4 { char pad0[0xc]; void* unknown_c_; void* unknown_10_; };
struct Struct_ov024_021e093c_5 { char pad[0x20]; struct Struct_ov024_021e093c_2 f20; struct Struct_ov024_021e093c_2 f24; };

// USA: func_ov024_021e093c
extern "C" ARM void* func_ov024_021e093c(struct Struct_ov024_021e093c_4* obj, int unused, int id, struct Struct_ov024_021e093c_5* range, int arg4, int arg5, unsigned char arg6) {
	GameObject* c = GetCombatantByID((int)obj->unknown_10_, id);
	if (!c) return 0;
	struct Struct_ov024_021e093c result;
	result.lo = 0;
	result.hi = 0;
	int active = func_02088980((unsigned char*)c->currentStats_);
	unsigned short sel;
	if (active != 0 && arg6 != 0) {
		func_02088994((unsigned char*)c->currentStats_);
		func_ov000_02159eac(obj->unknown_10_, &result, 0x2c);
		sel = func_ov024_021da644(id, range->f20.c, range->f24.a);
	} else {
		sel = func_ov024_021da644(id, range->f24.b, range->f24.c);
	}
	void* entry = func_ov000_0215e958(obj->unknown_10_);
	if (!entry) return 0;
	func_ov000_0215a88c(obj->unknown_10_, entry, sel);
	struct Struct_ov024_021e093c_3* var5 = (struct Struct_ov024_021e093c_3*)((char*)obj->unknown_c_ + 0x1c);
	func_ov000_0215cd44(obj->unknown_10_, entry, c, 0, result, var5->flag != 0);
	return entry;
}
