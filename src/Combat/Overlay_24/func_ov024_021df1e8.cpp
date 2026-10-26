#include <globaldefs.h>
#include "Combat/Overlay_0/GetCombatantByID.h"
#include "GameState/GameState.h"

extern "C" int func_ov024_021eae14(void* obj, int id);
extern "C" void* func_ov000_0215e958(void* a0);
extern "C" void func_ov000_0215cd44(void* a, void* b, void* c, int d, int e, int f, int g);

struct Struct_ov024_021df1e8 { unsigned char pad : 7; unsigned char flag : 1; };
struct Struct_ov024_021df1e8_2 { char pad0[0xc]; void* unknown_c_; void* unknown_10_; int unknown_14_; };

// USA: func_ov024_021df1e8
extern "C" ARM void* func_ov024_021df1e8(struct Struct_ov024_021df1e8_2* obj, int unused, int id) {
	GameObject* c = GetCombatantByID((int)obj->unknown_10_, id);
	if (!c) return 0;
	if (func_ov024_021eae14(obj, id) > 0) {
		obj->unknown_14_ = obj->unknown_14_ + 1;
	}
	void* entry = func_ov000_0215e958(obj->unknown_10_);
	if (!entry) return 0;
	struct Struct_ov024_021df1e8* var2 = (struct Struct_ov024_021df1e8*)((char*)obj->unknown_c_ + 0x1c);
	func_ov000_0215cd44(obj->unknown_10_, entry, c, 0, 0, 0, var2->flag != 0);
	return entry;
}
