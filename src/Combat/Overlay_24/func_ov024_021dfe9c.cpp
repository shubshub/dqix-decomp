#include <globaldefs.h>
#include "GameState/GameState.h"

extern "C" GameObject* func_ov000_021536f8(int unused, int id);
extern "C" void* func_ov000_0215e958(void* a0);
extern "C" void func_ov000_0215cd44(void* a, void* b, void* c, int d, int e, int f, int g);

struct Struct_ov024_021dfe9c { char pad0[0xc]; void* unknown_c_; void* unknown_10_; int unknown_14_; };
struct Struct_ov024_021dfe9c_2 { unsigned char pad : 7; unsigned char flag : 1; };

// USA: func_ov024_021dfe9c
extern "C" ARM void* func_ov024_021dfe9c(struct Struct_ov024_021dfe9c* obj, int unused, int id) {
	GameObject* c = func_ov000_021536f8((int)obj->unknown_10_, id);
	if (!c) return 0;
	void* extra = *(void**)((char*)c + 0x148);
	if (!extra) return 0;
	*(unsigned char*)((char*)c + 0x17e) = 1;
	obj->unknown_14_ += 1;
	void* entry = func_ov000_0215e958(obj->unknown_10_);
	if (!entry) return 0;
	struct Struct_ov024_021dfe9c_2* var3 = (struct Struct_ov024_021dfe9c_2*)((char*)obj->unknown_c_ + 0x1c);
	func_ov000_0215cd44(obj->unknown_10_, entry, c, 0, 0, 0, var3->flag != 0);
	return entry;
}
