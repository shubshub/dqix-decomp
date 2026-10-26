#include <globaldefs.h>

extern "C" int func_020a1fa8(void);
extern "C" int func_ov026_021dbd1c(void* p0, void* p1, int flag);

// USA: func_ov000_02163b14
extern "C" ARM int func_ov000_02163b14(void* p0, void* p1) {
	int v = func_020a1fa8();
	if (v != 3) {
		return v;
	}
	return func_ov026_021dbd1c(p0, p1, 1);
}
