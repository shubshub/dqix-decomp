#include <globaldefs.h>

extern "C" int func_ov001_02164194(void* entry, int type, int val, int flag);

// USA: func_ov001_02164214
extern "C" ARM int func_ov001_02164214(void* arr, int idx, int type, int val, int flag) {
	if (idx < 0 || idx >= 0x20) return 0;
	return func_ov001_02164194((char*)arr + idx * 0x10, type, val, flag);
}
