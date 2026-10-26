#include <globaldefs.h>
#include "Combat/Overlay_0/GetCombatantByID.h"
#include "GameState/GameState.h"

struct Struct_02070b6c_3;
struct Struct_ov024_021e1cbc_4 { char pad0[8]; void* field8; };
extern "C" Struct_ov024_021e1cbc_4* func_02070fd0(Struct_02070b6c_3* container, int key);
extern "C" void* func_ov000_0215e958(void* a0);
extern "C" void func_ov000_0215cd44(void* a, void* b, void* c, int d, int e, int f, int g);

struct Struct_ov024_021e1cbc_5 {
    unsigned int a : 10;
    unsigned int b : 10;
    unsigned int c : 10;
    unsigned int hi : 2;
};
struct Struct_ov024_021e1cbc_6 { char pad[0x20]; Struct_ov024_021e1cbc_5 f20; Struct_ov024_021e1cbc_5 f24; };

struct Struct_ov024_021e1cbc_7 { unsigned short key; char pad[0x18 - 2]; };
struct Struct_ov024_021e1cbc_8 { unsigned char lo : 4; unsigned char count : 2; unsigned char hi : 2; };
struct Struct_ov024_021e1cbc_9 {
    char pad0[0x81b1];
    Struct_ov024_021e1cbc_8 flags;
    char unknown_81b2_[2];
    Struct_ov024_021e1cbc_7 unknown_81b4_[4];
    char pad[0x8e18 - 0x81b4 - 4 * 0x18];
    char* data;
};

struct Struct_ov024_021e1cbc { char pad[0x1a]; unsigned short unknown_1a_; unsigned short field1c; };
struct Struct_ov024_021e1cbc_2 { unsigned char pad : 7; unsigned char flag : 1; };
struct Struct_ov024_021e1cbc_3 {
    char pad0[4];
    Struct_ov024_021e1cbc* msg;
    char pad8[4];
    void* unknown_c_;
    Struct_ov024_021e1cbc_9* battle;
    char pad2[0x6e - 0x14];
    unsigned char unknown_6e_;
};

// USA: func_ov024_021e1cbc
extern "C" ARM void* func_ov024_021e1cbc(Struct_ov024_021e1cbc_3* obj, int unused, int id, Struct_ov024_021e1cbc_6* range) {
	GameObject* c = GetCombatantByID((int)obj->battle, id);
	if (!c) return 0;
	int found = 0;
	char* data = obj->battle->data;
	for (int i = 0; i < obj->battle->flags.count; i++) {
		Struct_ov024_021e1cbc_4* e = func_02070fd0((Struct_02070b6c_3*)(data + 0x684), obj->battle->unknown_81b4_[i].key);
		if (e && e->field8) found = 1;
	}
	if (!found) {
		obj->msg->field1c = 0x1f;
		obj->msg->unknown_1a_ = 0x1f;
	} else {
		obj->msg->field1c = range->f24.a;
		obj->msg->unknown_1a_ = range->f20.c;
	}
	obj->unknown_6e_ = 1;
	void* entry = func_ov000_0215e958(obj->battle);
	if (!entry) return 0;
	Struct_ov024_021e1cbc_2* var6 = (Struct_ov024_021e1cbc_2*)((char*)obj->unknown_c_ + 0x1c);
	func_ov000_0215cd44(obj->battle, entry, c, 0, 0, 0, var6->flag != 0);
	return entry;
}
