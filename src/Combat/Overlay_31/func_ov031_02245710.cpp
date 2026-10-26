#include <globaldefs.h>

struct Struct_ov031_022456f0 { unsigned char unknown_0_[0x34]; unsigned char f34; unsigned char unknown_35_; };
extern "C" ARM int func_ov031_022456f0(Struct_ov031_022456f0* obj);

// USA: func_ov031_02245710
extern "C" ARM int func_ov031_02245710(Struct_ov031_022456f0* obj, int arg1) {
	if (arg1 != 0) return func_ov031_022456f0(obj);
	if (obj->f34 == 6) {
		if (obj->unknown_35_ == 2 || obj->unknown_35_ == 1) return func_ov031_022456f0(obj);
	}
	return 0;
}
