#include <globaldefs.h>
#include "Resource/ActionDataTables.h"
#include "std_library_functions.h"

struct S_10088;
extern "C" int func_02053c6c(unsigned char* obj);
extern "C" int func_020a35e0(unsigned char* obj, unsigned char index);
extern "C" int func_02010088(struct S_10088* obj);
struct Struct_ov024_021f6a1c;
extern "C" void func_ov024_021f6a1c(struct Struct_ov024_021f6a1c* obj, void* src);
extern "C" void func_ov024_021f9874(void* obj, void* buf, int slot, int value);

struct Struct_ov024_021fc068_5 {
	unsigned short hp;
	char pad2[0x14 - 0x2];
	unsigned int unknown_14_;
};

struct Struct_ov024_021fc068_6 {
	char pad0[4];
	short id;
	char pad6[0x138 - 0x6];
	struct Struct_ov024_021fc068_5* stats;
};

struct Struct_ov024_021fc068_6* GetCombatantByID(int unused, int id);

struct Struct_ov024_021fc068_7 {
	char pad0[4];
	unsigned int code : 12;
	unsigned int unknown_5_4_ : 20;
	unsigned int unknown_8_0_ : 8;
	unsigned int mode : 2;
	unsigned int unknown_9_2_ : 22;
	char unknown_c_[0x10 - 0xc];
	unsigned int flags10;
	unsigned int unknown_14_0_ : 28;
	unsigned int unknown_17_4_ : 4;
};

struct Struct_ov024_021fc068 {
	char pad[0x8e18];
	unsigned char* partyWork;
};

struct Struct_ov024_021fc068_2 {
	struct Struct_ov024_021fc068* battle;
	short id;
	char pad6[2];
	struct Struct_ov024_021fc068_6* self;
	char unknown_c_[0x128 - 0xc];
	int targetId;
	char unknown_12c_[0x64c - 0x12c];
	struct Struct_ov024_021fc068_7* action;
};

struct Struct_ov024_021fc068_3 {
	float value;
	unsigned char field4;
	unsigned char field5;
	unsigned char slot;
	unsigned char rate;
	unsigned char kind;
	char unknown_9_[3];
};

struct Struct_ov024_021fc068_4 {
	char entries[0xc4];
	float threshold;
};

// USA: func_ov024_021fc068
extern "C" ARM void func_ov024_021fc068(struct Struct_ov024_021fc068_2* obj) {
	struct Struct_ov024_021fc068_6* self = obj->self;
	func_02053c6c((unsigned char*)self);
	func_020797dc();
	struct Struct_ov024_021fc068_7* action = obj->action;
	if (action->mode == 1) return;
	GetCombatantByID((int)obj->battle, (short)obj->targetId);
	float rate = 50.0f;
	if (action->code == 0x27) {
		rate = 100.0f;
	} else if (action->code == 0x26 || action->code == 0x54) {
		rate = 50.0f;
	}
	struct Struct_ov024_021fc068_4 buf;
	memset(&buf, 0, sizeof(buf));
	memset(&buf, 0, sizeof(buf));
	for (int i = 0; i < 4; i++) {
		if (!func_020a35e0(obj->battle->partyWork, i)) continue;
		if (action->unknown_17_4_ == 1 && i != obj->id) continue;
		struct Struct_ov024_021fc068_6* c = GetCombatantByID((int)obj->battle, (short)i);
		if (!c) continue;
		if (!func_02010088((struct S_10088*)c)) continue;
		if ((action->flags10 & 0x400) && (c->stats->unknown_14_ & 0x200)) continue;
		struct Struct_ov024_021fc068_3 entry;
		entry.value = (float)(c->stats->hp / 2);
		entry.field5 = 0;
		entry.slot = i;
		entry.rate = (int)rate;
		entry.kind = 5;
		func_ov024_021f6a1c((struct Struct_ov024_021f6a1c*)&buf, &entry);
		if (action->unknown_17_4_ == 2 || action->unknown_17_4_ == 1) {
			func_ov024_021f9874(obj, &buf, 0, (unsigned char)c->id);
			memset(&buf, 0, sizeof(buf));
		}
	}
	if (action->unknown_17_4_ == 4 || action->unknown_17_4_ == 3) {
		GetCombatantByID((int)obj->battle, 0);
		int value = (unsigned char)self->id;
		if (action->unknown_17_4_ == 3) value = 0xff;
		func_ov024_021f9874(obj, &buf, 0, value);
	}
}
