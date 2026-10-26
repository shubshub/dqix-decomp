#include <globaldefs.h>
#include "std_library_functions.h"

extern "C" int func_ov024_021fe698(void* obj, int idx);
struct Struct_ov024_021fc754_5;
extern "C" int func_ov024_021fcac0(struct Struct_ov024_021fc754_5* obj);
extern "C" void func_ov024_021f9874(void* obj, void* buf, int zero, int val);

struct Struct_ov024_021fcd7c {
	char pad0[4];
	short field4;
	unsigned char kind;
	char unknown_7_;
	struct Struct_ov024_021fc754_5* combatant;
	int unknown_c_;
};

// USA: func_ov024_021fcd7c
extern "C" ARM void func_ov024_021fcd7c(struct Struct_ov024_021fcd7c* obj) {
	int trigger = 0;
	if (obj->kind == 2) trigger = 1;
	if (obj->kind == 0) return;
	if (obj->unknown_c_ >= 3) trigger = 1;
	if (!trigger) return;
	if (!func_ov024_021fe698(obj, 0x12)) return;
	if (func_ov024_021fcac0(obj->combatant)) return;
	char buf[0xc8];
	memset(buf, 0, 0xc8);
	*(float*)(buf + 0xc4) = 1000.0f;
	func_ov024_021f9874(obj, buf, 0, (unsigned char)obj->field4);
}
