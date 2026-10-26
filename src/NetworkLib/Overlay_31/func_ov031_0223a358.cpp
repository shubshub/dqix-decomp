#include <globaldefs.h>

extern "C" int func_ov031_02239b34(void);
extern "C" int func_ov031_02239368(int);

// USA: func_ov031_0223a358
extern "C" ARM int func_ov031_0223a358(void) {
	int r = func_ov031_02239b34();
	if (r != 0) {
		return r;
	}
	return func_ov031_02239368(10);
}
