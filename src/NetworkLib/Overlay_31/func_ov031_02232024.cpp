#include <globaldefs.h>

struct Struct_ov031_02290cbc { unsigned char b0; unsigned short h2; };
extern Struct_ov031_02290cbc data_ov031_02290cbc;

extern "C" void func_ov031_0223208c(void);
extern "C" void func_ov031_0222336c(int, int, int);
extern "C" void func_ov031_022239f4(void);
extern "C" void func_ov031_02223518(int);
extern "C" void func_ov031_022235a0(int);
extern "C" void func_ov031_02222b0c(int);
extern "C" void func_ov031_02235780(void);
extern "C" void func_ov031_022357e8(void);
extern "C" void func_ov031_02236878(int);
extern "C" void func_ov031_02232134(void);
extern "C" ARM void func_ov031_022274c0(int);

// USA: func_ov031_02232024
extern "C" ARM void func_ov031_02232024(void) {
	data_ov031_02290cbc.h2 = 0;
	data_ov031_02290cbc.b0 = 0;
	func_ov031_0223208c();
	func_ov031_0222336c(0x33, -1, 0);
	func_ov031_022239f4();
	func_ov031_02223518(2);
	func_ov031_022235a0(0x33);
	func_ov031_02222b0c(0);
	func_ov031_02235780();
	func_ov031_022357e8();
	func_ov031_02236878(0xa);
	func_ov031_022274c0((int)func_ov031_02232134);
}
