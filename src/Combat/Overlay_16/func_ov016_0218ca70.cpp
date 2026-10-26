#include <globaldefs.h>

// USA: func_ov016_0218ca70
extern "C" ARM unsigned short func_ov016_0218ca70(void) {
	unsigned short a = *(volatile unsigned short*)0x4000130;
	unsigned short b = *(volatile unsigned short*)0x27fffa8;
	return (unsigned short)(((a | b) ^ 0x2fff) & 0x2fff);
}
