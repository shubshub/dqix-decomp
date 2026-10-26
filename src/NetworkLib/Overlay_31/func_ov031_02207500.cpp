#include <globaldefs.h>

extern "C" unsigned int func_ov031_02206f3c();

// USA: func_ov031_02207500
extern "C" ARM unsigned int func_ov031_02207500() {
	unsigned int w = func_ov031_02206f3c();
	return ((w >> 24) & 0xff) | ((w >> 8) & 0xff00) | ((w << 8) & 0xff0000) | ((w << 24) & 0xff000000);
}
