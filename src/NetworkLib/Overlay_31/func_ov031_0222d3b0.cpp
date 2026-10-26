#include <globaldefs.h>

struct Struct_ov031_0222d3b0 {
	unsigned char pad0[4];
	int* field4;
	unsigned char pad8[0x29 - 8];
	unsigned char unknown_29_;
};
extern Struct_ov031_0222d3b0* data_ov031_02290c94;
extern unsigned char data_ov031_02248ecc[];
extern unsigned char data_ov031_02248ed0[];

// USA: func_ov031_0222d3b0
extern "C" ARM void func_ov031_0222d3b0(void) {
	unsigned char b = data_ov031_02290c94->unknown_29_;
	int* p = data_ov031_02290c94->field4;
	int var2 = b & 0xf;
	int idx1 = b >> 4;
	if (b >= 0x20) {
		idx1 = 1;
		var2 = 0xf;
	}
	unsigned char var4 = data_ov031_02248ecc[idx1];
	unsigned char t2 = data_ov031_02248ed0[var2];
	unsigned int val = *(unsigned int*)p;
	*(unsigned int*)p = (val & 0xfe00ff00u) | var4 | (((unsigned int)t2 << 23) >> 7);
}
