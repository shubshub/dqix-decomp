#include <globaldefs.h>
#include "std_library_functions.h"

struct Struct_ov000_0216fe48 {
	int f0;
	unsigned char pad0[0x84 - 0x4];
	int f84;
	unsigned char unknown_88_[0x18];
	unsigned char unknown_a0_;
	unsigned char unknown_a1_;
};

// USA: func_ov000_0216fe48
extern "C" ARM void func_ov000_0216fe48(struct Struct_ov000_0216fe48* obj) {
	obj->f0 = -1;
	obj->f84 = 0;
	obj->unknown_a0_ = 0;
	obj->unknown_a1_ = 0;
	memset(obj->unknown_88_, 0, 0x18);
}
