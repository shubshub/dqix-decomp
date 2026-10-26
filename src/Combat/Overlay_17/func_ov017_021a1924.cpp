#include <globaldefs.h>

struct S021a1924 { unsigned char f0; unsigned char f1; };

extern "C" void func_ov017_021a18c8(S021a1924*);

// USA: func_ov017_021a1924
extern "C" ARM void func_ov017_021a1924(S021a1924* obj) {
	func_ov017_021a18c8(obj);
	obj->f1 = 1;
}
