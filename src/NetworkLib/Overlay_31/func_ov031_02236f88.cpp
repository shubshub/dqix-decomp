#include <globaldefs.h>

struct Struct_ov031_02222f44_2;
extern "C" void func_ov031_0223bd28(Struct_ov031_02222f44_2*, int, unsigned int*, unsigned int*);
extern "C" void func_ov031_0223bbd8(void*, int, int, int);
extern "C" void func_ov031_0223e2b8(void*, int);
extern "C" void func_ov031_0223701c(void*);

struct Struct_ov031_02236f88 { void* items[5]; int f14; };
struct Struct_ov031_02290d04_11 { void* field0; Struct_ov031_02236f88* p; void* field8; void* fieldC; };
extern Struct_ov031_02290d04_11 data_ov031_02290d04;

// USA: func_ov031_02236f88
extern "C" ARM void func_ov031_02236f88(void* obj) {
	unsigned int var0, var1;
	func_ov031_0223bd28((Struct_ov031_02222f44_2*)data_ov031_02290d04.p->items[4], 0, &var0, &var1);
	var0 = var0 - 8;
	if ((int)var0 > 0x98) {
		func_ov031_0223bbd8(data_ov031_02290d04.p->items[4], -1, var0, 0x21);
		return;
	}
	var0 = 0x98;
	func_ov031_0223bbd8(data_ov031_02290d04.p->items[4], -1, var0, 0x21);
	func_ov031_0223e2b8(obj, (int)func_ov031_0223701c);
}
