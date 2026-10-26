#include <globaldefs.h>

extern "C" void func_ov031_02223720(int, int, int, int);
extern unsigned char data_ov031_02290c8c;
extern unsigned short data_ov031_02248e84[];
extern unsigned short data_ov031_02248e86[];
extern unsigned short data_ov031_02248e88[];

// USA: func_ov031_0222c8cc
extern "C" ARM void func_ov031_0222c8cc(void) {
	unsigned int idx = data_ov031_02290c8c;
	int flag = (idx < 4) ? 2 : 3;
	func_ov031_02223720(flag, data_ov031_02248e84[idx * 4], data_ov031_02248e88[idx * 4], data_ov031_02248e86[idx * 4]);
}
