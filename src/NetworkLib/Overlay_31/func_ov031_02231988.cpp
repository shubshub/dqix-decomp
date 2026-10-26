#include <globaldefs.h>

extern unsigned char data_ov031_02290cb4;
extern "C" void func_ov031_022319c4(void);
extern "C" void func_ov031_022239f4(void);
extern "C" void func_ov031_022235a0(int);
extern "C" void func_ov031_02236878(int);
extern "C" void func_ov031_02231a44(void);
extern "C" void func_ov031_022274c0(int v);

// USA: func_ov031_02231988
extern "C" ARM void func_ov031_02231988(void) {
	(&data_ov031_02290cb4)[0] = 0;
	func_ov031_022319c4();
	func_ov031_022239f4();
	func_ov031_022235a0(0x26);
	func_ov031_02236878(0x10);
	func_ov031_022274c0((int)func_ov031_02231a44);
}
