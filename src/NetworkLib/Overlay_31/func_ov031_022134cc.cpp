#include <globaldefs.h>

extern "C" char* func_ov031_022133f8(int);
extern "C" int func_ov031_022134b0(void);

// USA: func_ov031_022134cc
extern "C" ARM void func_ov031_022134cc(int v) {
	char *p = func_ov031_022133f8(1);
	*(int*)(p + 0xc) = v;
	*(p + 0xa) = (unsigned char)func_ov031_022134b0();
}
