#include <globaldefs.h>
#include "Combat/Overlay_0/GetCombatantByID.h"
#include "GameState/GameState.h"

extern "C" unsigned short func_ov024_021da644(int idx, int a, int b);
extern "C" void* func_ov000_0215e958(void* a0);
extern "C" void func_ov000_0215a88c(void* objRaw, void* arg1, int c);
extern "C" void func_ov000_0215cd44(void* a, void* b, void* c, int d, int e, int f, int g);

struct Struct_ov024_021e1328 {
	unsigned int a : 10;
	unsigned int b : 10;
	unsigned int c : 10;
	unsigned int hi : 2;
};

struct Struct_ov024_021e1328_2 { unsigned char pad : 7; unsigned char flag : 1; };
struct Struct_ov024_021e1328_3 { char pad0[0xc]; void* unknown_c_; void* unknown_10_; };
struct Struct_ov024_021e1328_4 { char pad[0x20]; struct Struct_ov024_021e1328 f20; struct Struct_ov024_021e1328 f24; };

// USA: func_ov024_021e1328
extern "C" ARM void* func_ov024_021e1328(struct Struct_ov024_021e1328_3* obj, int unused, int id, struct Struct_ov024_021e1328_4* range) {
	GameObject* c = GetCombatantByID((int)obj->unknown_10_, id);
	if (!c) return 0;
	unsigned short sel = func_ov024_021da644(id, range->f20.c, range->f24.a);
	void* entry = func_ov000_0215e958(obj->unknown_10_);
	if (!entry) return 0;
	func_ov000_0215a88c(obj->unknown_10_, entry, sel);
	struct Struct_ov024_021e1328_2* var3 = (struct Struct_ov024_021e1328_2*)((char*)obj->unknown_c_ + 0x1c);
	func_ov000_0215cd44(obj->unknown_10_, entry, c, 0, 0, 0, var3->flag != 0);
	return entry;
}
