#include <globaldefs.h>

extern "C" int func_020cee18(int*);
extern "C" int func_020cedfc(int);

// USA: func_ov031_0223dfd0
extern "C" ARM int func_ov031_0223dfd0(void) {
	int local;
	int result = func_020cee18(&local);
	if (result != 0) {
		return result;
	}
	if (local == 0xf) {
		return local;
	}
	return func_020cedfc(0xf);
}
