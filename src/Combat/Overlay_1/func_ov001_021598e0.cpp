#include <globaldefs.h>

// USA: func_ov001_021598e0
extern "C" ARM int func_ov001_021598e0(char* src, char* dst) {
	*(int*)(dst + 0x90) = *(int*)(src + 0x10);
	return 0;
}
