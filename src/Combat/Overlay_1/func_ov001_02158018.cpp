#include <globaldefs.h>

// USA: func_ov001_02158018
extern "C" ARM int func_ov001_02158018(char* src, char* dst) {
	*(int*)(dst + 0x68) = *(int*)(src + 0x1c);
	return 0;
}
