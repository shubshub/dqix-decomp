#include <globaldefs.h>

extern "C" int func_ov031_02225c74(void);
struct Struct_ov031_0222de54 { unsigned char pad[0x15]; unsigned char unknown_15_; };
extern Struct_ov031_0222de54 *data_ov031_02290c98;
extern "C" void func_ov031_022274c0(int);
extern "C" void func_ov031_0222dee0(void);
extern "C" void func_ov031_02237b2c(int, int, int, int, int);
extern "C" void func_ov031_0222e378(void);
extern "C" void func_ov031_0222e09c(void);

// USA: func_ov031_0222de54
extern "C" ARM void func_ov031_0222de54(void) {
	if (func_ov031_02225c74() != 0) return;
	unsigned char v = data_ov031_02290c98->unknown_15_;
	if (v == 0) {
		func_ov031_022274c0((int)func_ov031_0222dee0);
		return;
	}
	if (v == 2) {
		func_ov031_02237b2c(6, 3, 1, -1, 0);
		func_ov031_022274c0((int)func_ov031_0222e378);
		return;
	}
	func_ov031_02237b2c(0x47, 2, 1, -1, 0);
	func_ov031_022274c0((int)func_ov031_0222e09c);
}
