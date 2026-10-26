#include <globaldefs.h>

// USA: func_ov023_021e33a0
extern "C" ARM void func_ov023_021e33a0(char* p, signed char v) {
#if defined(jpn)
	*(signed char*)(p + 0x4e3) = *(signed char*)(p + 0x400 + 0xe2);
	*(signed char*)(p + 0x4e2) = v;
#else
	*(signed char*)(p + 0x4e7) = *(signed char*)(p + 0x400 + 0xe6);
	*(signed char*)(p + 0x4e6) = v;
#endif
}
