#include <globaldefs.h>

struct S021befcc { unsigned char f0; unsigned char f1; };

extern "C" void func_ov017_021bef84(S021befcc*);

// USA: func_ov017_021befcc
extern "C" ARM void func_ov017_021befcc(S021befcc* obj) {
	func_ov017_021bef84(obj);
	obj->f1 = 1;
}
