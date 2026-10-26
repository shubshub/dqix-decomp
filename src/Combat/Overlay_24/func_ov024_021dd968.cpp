#include <globaldefs.h>
#include "Combat/Overlay_0/GetCombatantByID.h"
#include "GameState/GameState.h"

struct Struct_02087d24;
struct Struct_02087d78;
extern "C" int func_02087d24(struct Struct_02087d24* p, int arg1);
extern "C" int func_02087d78(struct Struct_02087d78* p, int delta);
extern "C" void* func_ov000_0215e958(void* a0);
extern "C" void func_ov000_0215a88c(void* objRaw, void* arg1, int c);
extern "C" void func_ov000_0215cd44(void* a, void* b, void* c, int d, int e, int f, int g);

struct Struct_ov024_021dd968 { unsigned char pad : 7; unsigned char flag : 1; };
struct Struct_ov024_021dd968_2 { char pad0[0xc]; void* unknown_c_; void* unknown_10_; char unknown_14_[0x61]; unsigned char unknown_75_; };
struct Struct_ov024_021dd968_3 { char pad[0x30]; short unknown_30_; };

extern "C" int func_ov024_021e97f4(struct Struct_ov024_021dd968_2* ctx, int id, struct Struct_ov024_021dd968_3* parameters, unsigned char arg3, signed char value, unsigned char arg5, unsigned char special);
extern "C" void func_ov024_021e8bf0(void* work, void* fieldC, unsigned short* sel);

// USA: func_ov024_021dd968
extern "C" ARM void* func_ov024_021dd968(struct Struct_ov024_021dd968_2* obj, int unused, int id, struct Struct_ov024_021dd968_3* range, int arg4, int arg5, unsigned char arg6) {
	GameObject* c = GetCombatantByID((int)obj->unknown_10_, id);
	if (!c) return 0;
	unsigned char var1 = 0;
	int result = 0;
	int var3 = 0;
	int delta = range->unknown_30_;
	if (delta < -2) delta = -2;
	if (delta > 2) delta = 2;
	if (delta < 0) var3 = 1;
	if (func_02087d24((struct Struct_02087d24*)c->currentStats_, (unsigned char)var3) && arg6 != 0) {
		result = func_02087d78((struct Struct_02087d78*)c->currentStats_, (signed char)delta);
		var1 = 1;
	} else {
		obj->unknown_75_ = 0;
	}
	void* entry = func_ov000_0215e958(obj->unknown_10_);
	if (!entry) return 0;
	unsigned short sel = func_ov024_021e97f4(obj, id, range, var3, result, var1, arg6);
	func_ov024_021e8bf0(obj, obj->unknown_c_, &sel);
	func_ov000_0215a88c(obj->unknown_10_, entry, sel);
	struct Struct_ov024_021dd968* var7 = (struct Struct_ov024_021dd968*)((char*)obj->unknown_c_ + 0x1c);
	func_ov000_0215cd44(obj->unknown_10_, entry, c, 0, 0, 0, var7->flag != 0);
	return entry;
}
