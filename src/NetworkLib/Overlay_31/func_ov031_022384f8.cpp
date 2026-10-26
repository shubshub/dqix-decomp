#include <globaldefs.h>

struct Struct_ov031_02222f44_2;
extern "C" void func_ov031_0223bd28(Struct_ov031_02222f44_2*, int, unsigned int*, unsigned int*);

struct Struct_ov031_022384f8 { Struct_ov031_02222f44_2* header; unsigned char pad[0x1e - 4]; unsigned char unknown_1e_; };
extern Struct_ov031_022384f8* data_ov031_02290d10;

extern "C" void func_ov031_022381c8(int);
extern "C" void func_ov031_0223e2b8(void*, int);
extern "C" void func_ov031_022385e4(int);
extern "C" void func_ov031_02238588(int);

// USA: func_ov031_022384f8
extern "C" ARM void func_ov031_022384f8(void* arg) {
	unsigned int var0, var1;
	func_ov031_0223bd28(data_ov031_02290d10->header, 0, &var0, &var1);
	var1 = var1 + 0xc;
	func_ov031_022381c8((int)var1);
	if ((int)var1 < 0xc0) return;
	if (data_ov031_02290d10->unknown_1e_ != 0) {
		func_ov031_0223e2b8(arg, (int)func_ov031_02238588);
	} else {
		func_ov031_0223e2b8(arg, (int)func_ov031_022385e4);
	}
}
