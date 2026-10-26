#include <globaldefs.h>
#include "GameState/GameState.h"

struct Struct_02088f68;
extern "C" GameObject* func_ov000_021536f8(int unused, int id);
extern "C" void* func_ov000_02160130(void);
extern "C" void func_ov000_02161e30(void* work, int id, int msg, int a3);
extern "C" void* func_ov000_0215e958(void* a0);
extern "C" void func_ov000_0215fd7c(void* obj);
extern "C" void func_ov000_0215a88c(void* objRaw, void* arg1, int c);
extern "C" void func_02088f68(struct Struct_02088f68* obj);
extern "C" void func_ov000_0215cd44(void* a, void* b, void* c, int d, int e, int f, int g);

struct Struct_ov024_021e0d00 { char pad0[0xc]; void* unknown_c_; void* unknown_10_; };

struct Struct_ov024_021e0d00_2 {
	char pad0[4];
	unsigned int unknown_4_0_ : 12;
	unsigned int : 20;
	char pad8[0x24 - 0x8];
	unsigned int unknown_24_0_ : 10;
	unsigned int : 22;
};

struct Struct_ov024_021e0d00_3 {
	GameObject base;
	char unknown_13c_[0x188 - 0x13c];
	unsigned short unknown_188_;
	unsigned short unknown_18a_;
};

struct Struct_ov024_021e0d00_4 {
	char pad0[0xe];
	unsigned short unknown_e_;
	unsigned short unknown_10_;
	unsigned short unknown_12_;
	unsigned short unknown_14_;
	char pad16[0x20 - 0x16];
	int unknown_20_;
};

// USA: func_ov024_021e0d00
extern "C" ARM void* func_ov024_021e0d00(struct Struct_ov024_021e0d00* obj, int arg1, int id, struct Struct_ov024_021e0d00_2* action) {
	struct Struct_ov024_021e0d00_3* c = (struct Struct_ov024_021e0d00_3*)func_ov000_021536f8((int)obj->unknown_10_, id);
	if (!c) return 0;
	if (arg1 == id) {
		int msg = -1;
		if (action->unknown_4_0_ == 0x153) msg = 0xb3;
		if (action->unknown_4_0_ == 0x31a) msg = 0x4b;
		func_ov000_02161e30(func_ov000_02160130(), id, msg, 1);
		struct Struct_ov024_021e0d00_4* entry = (struct Struct_ov024_021e0d00_4*)func_ov000_0215e958(obj->unknown_10_);
		if (!entry) return 0;
		func_ov000_0215fd7c(entry);
		entry->unknown_20_ = 0;
		entry->unknown_e_ = c->unknown_188_;
		entry->unknown_10_ = c->unknown_18a_;
		entry->unknown_12_ = c->unknown_188_;
		entry->unknown_14_ = c->unknown_18a_;
		func_ov000_0215a88c(obj->unknown_10_, entry, (unsigned short)action->unknown_24_0_);
		return entry;
	}
	c->base.currentStats_->primaryStats.currHP = 0;
	func_02088f68((struct Struct_02088f68*)c->base.currentStats_);
	void* entry = func_ov000_0215e958(obj->unknown_10_);
	if (!entry) return 0;
	func_ov000_0215cd44(obj->unknown_10_, entry, c, 0, 0, 0, 0);
	return entry;
}
