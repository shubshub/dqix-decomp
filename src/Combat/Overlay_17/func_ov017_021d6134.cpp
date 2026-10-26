#include <globaldefs.h>

struct Struct_ov001_0216089c { int type; int *ptr; };

// USA: func_ov017_021d6134
extern "C" ARM void func_ov017_021d6134(Struct_ov001_0216089c *a, int val) {
	if (a->type == 3) {
		a->ptr[1] = val;
	}
}
