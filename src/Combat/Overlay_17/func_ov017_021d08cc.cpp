#include <globaldefs.h>

extern "C" void func_ov017_0219949c(int a, int b, unsigned char c, unsigned char d, signed char e);
extern "C" void func_ov017_02199578(int a, int b, unsigned char c, unsigned char d, signed char e);

struct Struct_ov017_021d08cc {
	unsigned char pad0[4];
	unsigned char field4;
	unsigned char field5;
	unsigned char field6;
	signed char unknown_7_;
};

// USA: func_ov017_021d08cc
extern "C" ARM void func_ov017_021d08cc(int arg0, Struct_ov017_021d08cc* evt, int arg2, int table) {
	if (evt->field6 == 0) {
		func_ov017_0219949c(table, arg0, evt->field4, evt->field5, evt->unknown_7_);
	} else if (evt->field6 == 1) {
		func_ov017_02199578(table, arg0, evt->field4, evt->field5, evt->unknown_7_);
	}
}
