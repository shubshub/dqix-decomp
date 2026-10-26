#include <globaldefs.h>

struct S021c031c { unsigned char f0; unsigned char f1; };

extern "C" void func_ov017_021c0160(S021c031c*);

// USA: func_ov017_021c031c
extern "C" ARM void func_ov017_021c031c(S021c031c* obj) {
	func_ov017_021c0160(obj);
	obj->f1 = 1;
}
