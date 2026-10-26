#include <globaldefs.h>

// USA: func_ov001_02158028
extern "C" ARM int func_ov001_02158028(char* src, char* dst) {
	*(int*)(dst + 0x6c) = *(int*)(src + 0x1c);
	return 0;
}
