#include <globaldefs.h>

// USA: func_ov031_0220b148
extern "C" ARM unsigned int func_ov031_0220b148(unsigned int t, unsigned int* w) {
	unsigned int A = w[(t + 13) & 0xf];
	unsigned int B = w[t ^ 8];
	unsigned int C = w[(t + 2) & 0xf];
	unsigned int var3 = w[t];
	unsigned int x = var3 ^ (C ^ (A ^ B));
	unsigned int rot = (x << 1) | (x >> 31);
	w[t] = rot;
	return rot;
}
