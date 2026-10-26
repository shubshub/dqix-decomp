#include <globaldefs.h>

extern "C" int func_ov031_02222e0c(void);
extern "C" void func_ov031_02222e40(int v);
extern "C" void func_ov031_0221ae00(void* buf);
extern "C" int func_ov031_02236878(int index);
extern "C" int func_ov031_02229748(void);
extern "C" void func_ov031_022274c0(int fn);
extern "C" void func_ov031_02229528(void);

struct Struct_ov031_02229484 { unsigned long long unknown_0_; unsigned long long unknown_8_; int pad; };

struct Struct_ov031_02290c5c_3 { unsigned char idx; unsigned char flag; };
extern Struct_ov031_02290c5c_3 data_ov031_02290c5c;

// USA: func_ov031_02229484
extern "C" ARM void func_ov031_02229484(void) {
	int var0 = func_ov031_02222e0c();
	switch (var0) {
	case 0:
		func_ov031_02236878(7);
		break;
	case 1: {
		Struct_ov031_02229484 buf;
		func_ov031_0221ae00(&buf);
		if (data_ov031_02290c5c.idx != 0 && buf.unknown_0_ == 0) {
			func_ov031_02236878(9);
			func_ov031_02222e40(-1);
			return;
		}
		func_ov031_02236878(6);
		func_ov031_02229748();
		data_ov031_02290c5c.flag = 1;
		break;
	}
	default:
		return;
	}
	func_ov031_022274c0((int)func_ov031_02229528);
}
