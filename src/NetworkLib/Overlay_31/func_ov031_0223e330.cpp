#include <globaldefs.h>

extern char* data_ov031_02290d9c;

// USA: func_ov031_0223e330
extern "C" ARM void func_ov031_0223e330(int idx, unsigned char val) {
	*(unsigned char*)(data_ov031_02290d9c + (idx << 0x6) + 0x38) = val;
}
