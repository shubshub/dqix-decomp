#include <globaldefs.h>

extern unsigned char data_ov031_02290cb0;
extern "C" void func_ov031_02231594(void);
extern "C" void func_ov031_022239f4(void);
extern "C" void func_ov031_022235a0(int);
extern "C" void func_ov031_02222b0c(int);
extern "C" void func_ov031_02231614(void);
extern "C" void func_ov031_022274c0(int v);

// USA: func_ov031_02231558
extern "C" ARM void func_ov031_02231558(void) {
	(&data_ov031_02290cb0)[0] = 0;
	func_ov031_02231594();
	func_ov031_022239f4();
	func_ov031_022235a0(0x2a);
	func_ov031_02222b0c(2);
	func_ov031_022274c0((int)func_ov031_02231614);
}
