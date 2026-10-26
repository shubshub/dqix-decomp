#include <globaldefs.h>

// USA: func_ov001_02158338
extern "C" ARM int func_ov001_02158338(char* src, char* dst) {
	*(int*)(dst + 0x2e0) = *(int*)(src + 0x1c);
	return 0;
}
