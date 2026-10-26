#include <globaldefs.h>
#include "GameState/GameState.h"

extern "C" GameObject* func_ov000_021536f8(int unused, int id);
extern "C" void func_020488ac(unsigned char* obj, int value);
extern "C" int func_ov024_021eb08c(void* obj, int mode, int id, int a3);
extern "C" void func_ov000_0215a908(void* a0, int id);
extern "C" void* func_ov000_0215e958(void* a0);
extern "C" void func_ov000_0215cd44(void* a, void* b, void* c, int d, int e, int f, int g);

struct Struct_ov024_021e05e4 { char unk[0x18]; int flags; };
struct Struct_ov024_021e04e0 { char unk[0x138]; struct Struct_ov024_021e05e4* inner; };
extern "C" int func_ov024_021e05e4(struct Struct_ov024_021e04e0* obj);

struct Struct_ov024_021e04e0_2 { unsigned char pad : 7; unsigned char flag : 1; };
struct Struct_ov024_021e04e0_3 { char pad0[0xc]; void* unknown_c_; void* unknown_10_; int unknown_14_; };

// USA: func_ov024_021e04e0
extern "C" ARM void* func_ov024_021e04e0(struct Struct_ov024_021e04e0_3* obj, short value, int id) {
	GameObject* c = func_ov000_021536f8((int)obj->unknown_10_, id);
	if (!c) return 0;
	if (func_ov024_021e05e4((struct Struct_ov024_021e04e0*)c)) {
		*(short*)((char*)c->currentStats_ + 0x2e) = value;
		func_020488ac((unsigned char*)c, 1);
		func_ov000_0215a908(obj->unknown_10_, id);
		*(unsigned char*)((char*)c + 0x182) = 1;
		obj->unknown_14_++;
	} else if (func_ov024_021eb08c(obj, value, id, 0x12) != 0) {
		func_ov000_0215a908(obj->unknown_10_, id);
		*(unsigned char*)((char*)c + 0x182) = 1;
		obj->unknown_14_++;
	}
	void* entry = func_ov000_0215e958(obj->unknown_10_);
	if (!entry) return 0;
	struct Struct_ov024_021e04e0_2* var2 = (struct Struct_ov024_021e04e0_2*)((char*)obj->unknown_c_ + 0x1c);
	func_ov000_0215cd44(obj->unknown_10_, entry, c, 0, 0, 0, var2->flag != 0);
	return entry;
}
