#include <globaldefs.h>

extern "C" int func_ov031_022036a8(int, int, int, int);

// USA: func_ov031_0220376c
extern "C" ARM int func_ov031_0220376c(int a, int b, int c, int d, int e, int f) {
	int result = func_ov031_022036a8(a, b, e, f);
	if (result != 0 && d != 0) {
		return func_ov031_022036a8(c, d, e, 0);
	}
	return result;
}
