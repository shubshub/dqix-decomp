#include <globaldefs.h>

extern unsigned char data_ov031_02290cac;
extern "C" void func_ov031_0223117c(void);
extern "C" void func_ov031_022239f4(void);
extern "C" void func_ov031_022235a0(int);
extern "C" void func_ov031_02222b0c(int);
extern "C" void func_ov031_022311fc(void);
extern "C" void func_ov031_022274c0(int v);

// USA: func_ov031_02231140
extern "C" ARM void func_ov031_02231140(void) {
	(&data_ov031_02290cac)[0] = 0;
	func_ov031_0223117c();
	func_ov031_022239f4();
	func_ov031_022235a0(0x25);
	func_ov031_02222b0c(1);
	func_ov031_022274c0((int)func_ov031_022311fc);
}
