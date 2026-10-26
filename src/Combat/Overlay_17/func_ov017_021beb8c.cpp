#include <globaldefs.h>

struct S021beb8c { unsigned char f0; unsigned char f1; };

extern "C" void func_ov017_021beb48(S021beb8c*);

// USA: func_ov017_021beb8c
extern "C" ARM void func_ov017_021beb8c(S021beb8c* obj) {
	func_ov017_021beb48(obj);
	obj->f1 = 1;
}
