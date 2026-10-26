#include <globaldefs.h>

extern "C" void func_ov031_0223b710(void*);
extern void* data_ov031_02290d2c[];

// USA: func_ov031_0223bd88
extern "C" ARM void func_ov031_0223bd88(int idx) {
	func_ov031_0223b710(data_ov031_02290d2c[idx]);
	data_ov031_02290d2c[idx] = 0;
}
