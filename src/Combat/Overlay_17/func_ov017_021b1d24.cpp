#include <globaldefs.h>

struct S021b1d24 { unsigned char f0; unsigned char f1; };

extern "C" void func_ov017_021b14ec(S021b1d24*);

// USA: func_ov017_021b1d24
extern "C" ARM void func_ov017_021b1d24(S021b1d24* obj) {
	func_ov017_021b14ec(obj);
	obj->f1 = 1;
}
