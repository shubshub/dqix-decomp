#include <globaldefs.h>

// USA: func_ov001_0215ad2c
extern "C" ARM int func_ov001_0215ad2c(int x) {
	if (x < 0) {
		x = 0 - x;
		x = x + 0x9f;
	}
	return x;
}
