#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Util/Random.h"

extern "C" GameObject* func_ov000_021536f8(int unused, int id);
extern "C" int func_02088e04(unsigned char* obj);
extern "C" void func_02088e48(unsigned char* obj, unsigned char val);
extern "C" void func_020488ac(unsigned char* obj, int value);
extern "C" void func_ov000_0215a908(void* a0, int id);
extern "C" void* func_ov000_0215e958(void* a0);
extern "C" void func_ov000_0215cd44(void* a, void* b, void* c, int d, int e, int f, int g);

struct Struct_ov024_021e1de8 { unsigned char pad : 7; unsigned char flag : 1; };
struct Struct_ov024_021e1de8_2 { char pad0[0xc]; void* unknown_c_; void* unknown_10_; };
struct Struct_ov024_021e1de8_3 { char pad[0x28]; unsigned char lo; unsigned char hi; };

// USA: func_ov024_021e1de8
extern "C" ARM void* func_ov024_021e1de8(struct Struct_ov024_021e1de8_2* obj, short value, int id) {
	GameObject* c = func_ov000_021536f8((int)obj->unknown_10_, id);
	if (!c) return 0;
	struct Struct_ov024_021e1de8_3* extra = *(struct Struct_ov024_021e1de8_3**)((char*)c + 0x148);
	if (!extra) return 0;
	if (func_02088e04((unsigned char*)c->currentStats_)) {
		int var2 = NextRandomBetween((struct Random*)obj->unknown_10_, extra->lo, extra->hi);
		if (var2 > 0) {
			func_02088e48((unsigned char*)c->currentStats_, (unsigned char)var2);
			func_020488ac((unsigned char*)c, 1);
			*(short*)((char*)c->currentStats_ + 0x2e) = value;
			func_ov000_0215a908(obj->unknown_10_, id);
		}
	}
	void* entry = func_ov000_0215e958(obj->unknown_10_);
	if (!entry) return 0;
	struct Struct_ov024_021e1de8* var4 = (struct Struct_ov024_021e1de8*)((char*)obj->unknown_c_ + 0x1c);
	func_ov000_0215cd44(obj->unknown_10_, entry, c, 0, 0, 0, var4->flag != 0);
	return entry;
}
