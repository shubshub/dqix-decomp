#include <globaldefs.h>

extern "C" int func_ov031_0223c054(int);
extern "C" ARM int func_ov031_02222ddc(void);
extern "C" void func_ov031_0223c078(int, int, int, int);
extern "C" ARM void func_ov031_022274c0(int);
extern "C" void func_ov031_0222b290(void);

struct Struct_ov031_02290c80_4 { unsigned char flag; };
extern Struct_ov031_02290c80_4 data_ov031_02290c80;

// USA: func_ov031_0222b22c
extern "C" ARM void func_ov031_0222b22c(void) {
	if (func_ov031_0223c054(1) != 0) {
		return;
	}
	func_ov031_02222ddc();
	if (data_ov031_02290c80.flag == 0) {
		func_ov031_0223c078(3, 1, 1, 8);
	}
	func_ov031_0223c078(3, 0, 0x15, 8);
	func_ov031_022274c0((int)func_ov031_0222b290);
}
