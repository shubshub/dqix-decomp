#include <globaldefs.h>

// USA: func_ov031_0220781c
extern "C" ARM void func_ov031_0220781c(unsigned int v, unsigned char* out) {
	out[0] = (unsigned char)(v >> 0x18);
	out[1] = (unsigned char)(v >> 0x10);
	out[2] = (unsigned char)(v >> 0x8);
	out[3] = (unsigned char)v;
}
