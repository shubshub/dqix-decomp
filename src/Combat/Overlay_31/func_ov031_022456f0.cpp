#include <globaldefs.h>

struct Struct_ov031_022456f0 { unsigned char unknown_0_[0x34]; unsigned char f34; unsigned char unknown_35_; };

// USA: func_ov031_022456f0
extern "C" ARM int func_ov031_022456f0(Struct_ov031_022456f0* obj) {
	if (obj->f34 == 7 || obj->f34 == 6) {
		obj->unknown_35_ = 5;
		return 1;
	}
	return 0;
}
