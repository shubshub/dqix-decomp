#include <globaldefs.h>

// USA: func_ov031_02231120
extern "C" ARM int func_ov031_02231120(void) {
	int v = (*(unsigned short*)0x27fffa8 & 0x8000) >> 15;
	return v ? 1 : 0;
}
