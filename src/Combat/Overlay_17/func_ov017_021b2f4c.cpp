#include <globaldefs.h>

struct S021b2f4c { unsigned char f0; unsigned char f1; };

extern "C" void func_ov017_021b2c88(S021b2f4c*);

// USA: func_ov017_021b2f4c
extern "C" ARM void func_ov017_021b2f4c(S021b2f4c* obj) {
	func_ov017_021b2c88(obj);
	obj->f1 = 1;
}
