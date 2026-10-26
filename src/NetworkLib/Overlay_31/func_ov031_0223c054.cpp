#include <globaldefs.h>

extern void* data_ov031_02290d34;

// USA: func_ov031_0223c054
extern "C" ARM int func_ov031_0223c054(int arg) {
	char* p;
	if (arg == 1) p = (char*)data_ov031_02290d34;
	else p = (char*)data_ov031_02290d34 + 0xc;
	return *(unsigned char*)(p + 9);
}
