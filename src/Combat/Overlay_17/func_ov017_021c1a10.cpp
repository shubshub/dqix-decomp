#include <globaldefs.h>

struct Obj1_021c1a10 { unsigned char b0; unsigned char b1; };
extern "C" void func_ov017_021c1a24(Obj1_021c1a10* obj);

// USA: func_ov017_021c1a10
extern "C" ARM void func_ov017_021c1a10(Obj1_021c1a10* obj) {
	obj->b1 = 1;
	func_ov017_021c1a24(obj);
}
