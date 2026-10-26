#include <globaldefs.h>

extern "C" int func_ov031_02210ef8(void);
extern "C" int func_ov031_0221042c(int arg);

// USA: func_ov031_0221032c
extern "C" ARM int func_ov031_0221032c(int arg) {
	int r = -0x38;
	if (func_ov031_02210ef8()) {
		r = func_ov031_0221042c(arg);
	}
	return r;
}
