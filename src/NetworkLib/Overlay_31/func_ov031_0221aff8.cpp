#include <globaldefs.h>

extern int data_ov031_0224e6a0[];
extern "C" int func_ov031_0221b6f0(int, int, int);

// USA: func_ov031_0221aff8
extern "C" ARM int func_ov031_0221aff8(int v) {
	return func_ov031_0221b6f0(data_ov031_0224e6a0[2], 0x400, v) != 0;
}
