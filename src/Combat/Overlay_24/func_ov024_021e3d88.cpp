#include <globaldefs.h>
#include "Combat/Overlay_0/GetCombatantByID.h"
#include "GameState/GameState.h"
#include "Util/Random.h"

struct Struct_02087d24;
extern "C" int func_02087d24(struct Struct_02087d24* p, int arg1);
struct Struct_02087d78;
extern "C" int func_02087d78(struct Struct_02087d78* p, int delta);
struct Struct_ov024_021e2bd0;
extern "C" void* func_ov024_021e8ca0(struct Struct_ov024_021e2bd0* obj, int id);
extern "C" void func_ov000_0215cd44(void* a, void* b, void* c, int d, int e, int f, int g);

struct Struct_ov024_021e3d88 { unsigned char pad : 7; unsigned char flag : 1; };
struct Struct_ov024_021e3d88_2 { char pad0[0xc]; void* unknown_c_; struct Random* unknown_10_; };
struct Struct_ov024_021e3d88_3 { char pad[0x32]; short unknown_32_; };
struct Struct_ov024_021e3d88_4 { char pad[0x52]; unsigned char unknown_52_; };

// USA: func_ov024_021e3d88
extern "C" ARM unsigned long long func_ov024_021e3d88(struct Struct_ov024_021e3d88_2* obj, int unused, int id, struct Struct_ov024_021e3d88_3* move, int count) {
	if (count <= 0) return 0;
	GameObject* c = GetCombatantByID((int)obj->unknown_10_, id);
	if (!c) return 0;
	int roll = NextRandomMax(obj->unknown_10_, 100);
	int delta = move->unknown_32_;
	if (delta < -2) delta = -2;
	if (delta > 2) delta = 2;
	int var3 = 0;
	if (delta < 0) {
		unsigned char var4 = ((struct Struct_ov024_021e3d88_4*)c->currentStats_)->unknown_52_;
		if (var4 == 0) return 0;
		struct Struct_ov024_021e3d88* var5 = (struct Struct_ov024_021e3d88*)((char*)obj->unknown_c_ + 0x1c);
		if (!var5->flag) {
			float rate = var4;
			if (roll >= var4) return 0;
		}
		var3 = 1;
	}
	int var7 = 0;
	int result = 0;
	if (func_02087d24((struct Struct_02087d24*)c->currentStats_, (unsigned char)var3)) {
		result = func_02087d78((struct Struct_02087d78*)c->currentStats_, (signed char)delta);
		var7 = 1;
	}
	if (var7) {
		int msg;
		if (delta > 0) {
			switch (result) {
			case 2: msg = 0xab; break;
			case 0: msg = 0xae; break;
			default: msg = 0xac; break;
			}
		} else {
			switch (result) {
			case -2: msg = 0xaf; break;
			case 0: msg = 0xae; break;
			default: msg = 0xad; break;
			}
		}
		void* entry = func_ov024_021e8ca0((struct Struct_ov024_021e2bd0*)obj, msg);
		if (entry) {
			func_ov000_0215cd44(obj->unknown_10_, entry, c, 0, 0, 0, 0);
		}
	}
	return 0;
}
