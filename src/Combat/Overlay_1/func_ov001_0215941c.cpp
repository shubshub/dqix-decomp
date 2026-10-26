#include <globaldefs.h>

// USA: func_ov001_0215941c
extern "C" ARM int func_ov001_0215941c(char* src, char* dst) {
	*(int*)(dst + 0x1dc) = *(int*)(src + 0x10);
	return 0;
}
