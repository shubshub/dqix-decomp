#include <globaldefs.h>

extern int data_ov031_0224e6a0[];
extern "C" int func_ov031_0221b6f0(int, int, int);

// USA: func_ov031_0221add4
extern "C" ARM int func_ov031_0221add4(int v) {
	return func_ov031_0221b6f0(data_ov031_0224e6a0[2], 0x300, v) != 0;
}
