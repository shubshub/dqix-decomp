#include <globaldefs.h>

// USA: func_ov001_02158008
extern "C" ARM int func_ov001_02158008(char* src, char* dst) {
	*(int*)(dst + 0x64) = *(int*)(src + 0x1c);
	return 0;
}
