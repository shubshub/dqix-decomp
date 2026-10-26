#include <globaldefs.h>

extern "C" void func_ov031_022357b4(void);
extern "C" void func_ov031_02227520(int*, int*);
extern "C" void func_ov031_02234118(void);
extern "C" void func_ov031_0222336c(int, int, int);
extern "C" void func_ov031_022239f4(void);
extern "C" void func_ov031_02236174(void);
extern "C" void func_ov031_02234184(void);
extern "C" ARM void func_ov031_022274c0(int);

// USA: func_ov031_022340c0
extern "C" ARM void func_ov031_022340c0(void) {
	func_ov031_022357b4();
	int idx;
	func_ov031_02227520(NULL, &idx);
	func_ov031_02234118();
	func_ov031_0222336c(0x31, -1, 0);
	if (idx != 2) {
		func_ov031_022239f4();
	}
	if (idx == 1) {
		func_ov031_02236174();
	}
	func_ov031_022274c0((int)func_ov031_02234184);
}
