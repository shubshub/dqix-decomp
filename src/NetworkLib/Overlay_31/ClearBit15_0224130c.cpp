#include <globaldefs.h>

// USA: func_ov031_0224130c
extern "C" ARM int func_ov031_0224130c(int v) {
	if (v & 0x8000) {
		v &= ~0x8000;
	}
	return v;
}
