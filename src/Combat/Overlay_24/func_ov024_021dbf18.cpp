#include <globaldefs.h>
#include "Combat/Overlay_0/GetCombatantByID.h"
#include "GameState/GameState.h"

struct Struct_ov024_021dbf18 {
	unsigned int a : 10;
	unsigned int b : 10;
	unsigned int c : 10;
	unsigned int hi : 2;
};

struct Struct_ov024_021dbf18_2 { unsigned char pad : 7; unsigned char flag : 1; };
struct Struct_ov024_021dbf18_3 { char pad0[0x1c]; struct Struct_ov024_021dbf18_2 flags; };
struct Struct_ov024_021dbf18_4 { char pad0[0xc]; struct Struct_ov024_021dbf18_3* ctx; void* unknown_10_; int unknown_14_; };
struct Struct_ov024_021dbf18_5 { char pad[0x20]; struct Struct_ov024_021dbf18 f20; struct Struct_ov024_021dbf18 f24; };
struct Struct_ov024_021dbf18_6 { char pad[0x3b]; unsigned char bit0 : 1; unsigned char rest : 7; };

extern "C" unsigned long long func_ov024_021e4b14(struct Struct_ov024_021dbf18_4* obj, int a1, int id, struct Struct_ov024_021dbf18_5* range, int mode);
extern "C" int func_020882f8(unsigned char* obj);
extern "C" void func_02088390(void* obj);
extern "C" void func_ov000_02159eac(void* a0, void* buf, int a2);
extern "C" int func_ov000_02159f18(void* a0, unsigned long long mask, int kind);
extern "C" unsigned short func_ov024_021da644(int idx, int a, int b);
extern "C" void* func_ov000_0215e958(void* a0);
extern "C" void func_ov000_0215a88c(void* objRaw, void* arg1, int c);
extern "C" void func_ov000_0215cd44(void* a, void* b, void* c, int d, unsigned long long e, int g);

// USA: func_ov024_021dbf18
extern "C" ARM void* func_ov024_021dbf18(struct Struct_ov024_021dbf18_4* obj, int a1, int id, struct Struct_ov024_021dbf18_5* range, int arg4, int arg5, unsigned char arg6) {
	GameObject* c = GetCombatantByID((int)obj->unknown_10_, id);
	if (!c) return 0;
	int msg = 0;
	int var2 = 0;
	unsigned long long mask = 0;
	if (arg6) {
		mask = func_ov024_021e4b14(obj, a1, id, range, 1);
		if (func_020882f8((unsigned char*)c->currentStats_)) {
			msg = 0x40;
			func_02088390(c->currentStats_);
			if (mask == 0) {
				func_ov000_02159eac(obj->unknown_10_, &mask, 0x10);
			}
			((struct Struct_ov024_021dbf18_6*)c->currentStats_)->bit0 = 1;
			var2 = 1;
			obj->unknown_14_++;
		}
	}
	if (func_ov000_02159f18(obj->unknown_10_, mask, 0x19)) {
		if (!var2) {
			obj->unknown_14_++;
			var2 = 1;
		}
		msg = 0x173;
	}
	if (!var2) {
		msg = func_ov024_021da644(id, range->f24.b, range->f24.c);
	}
	void* entry = func_ov000_0215e958(obj->unknown_10_);
	if (!entry) return 0;
	func_ov000_0215a88c(obj->unknown_10_, entry, msg);
	func_ov000_0215cd44(obj->unknown_10_, entry, c, 0, mask, obj->ctx->flags.flag != 0);
	return entry;
}
