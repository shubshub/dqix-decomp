#include <globaldefs.h>

// USA: func_ov031_0220db64
extern "C" ARM unsigned int func_ov031_0220db64(unsigned int value) {
	asm {
		clz value, value
	}
	return value;
}
