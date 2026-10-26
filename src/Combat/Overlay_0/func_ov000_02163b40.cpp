#include <globaldefs.h>

extern "C" int func_020a1fa8(void);
extern "C" int func_ov026_021dbe44(void* p);

// USA: func_ov000_02163b40
extern "C" ARM int func_ov000_02163b40(void* p) {
	int v = func_020a1fa8();
	if (v != 3) {
		return v;
	}
	return func_ov026_021dbe44(p);
}
