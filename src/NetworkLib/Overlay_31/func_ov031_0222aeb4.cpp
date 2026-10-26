#include <globaldefs.h>

extern char data_ov031_02290c80;
extern "C" void func_ov031_0222af14(void);
extern "C" void func_ov031_022239f4(void);
extern "C" int func_ov031_0222336c(int, int, int);
extern "C" int func_ov031_02223518(void *obj);
extern "C" void func_ov031_022235a0(int);
extern "C" void func_ov031_02222b0c(int);
extern "C" void func_ov031_02226e08(void);
extern "C" void func_ov031_02236878(int);
extern "C" void func_ov031_0222afbc(void);
extern "C" void func_ov031_022274c0(int);

// USA: func_ov031_0222aeb4
extern "C" ARM void func_ov031_0222aeb4(void) {
	*(short*)(&data_ov031_02290c80 + 2) = 0;
	func_ov031_0222af14();
	func_ov031_022239f4();
	func_ov031_0222336c(0x36, 0x36 - 0x37, 0);
	func_ov031_02223518((void*)2);
	func_ov031_022235a0(0x22);
	func_ov031_02222b0c(0);
	func_ov031_02226e08();
	func_ov031_02236878(0xb);
	func_ov031_022274c0((int)func_ov031_0222afbc);
}
