#include <globaldefs.h>
#include "std_library_functions.h"

struct Struct_ov000_0215fef0 {
	unsigned char pad0[0xc];
	short f0xc;
	unsigned char f0xe[6];
	unsigned char pad1[0x20 - 0x14];
};

// USA: func_ov000_0215fef0
extern "C" ARM void func_ov000_0215fef0(struct Struct_ov000_0215fef0* obj) {
	memset(obj, 0, 0x20);
	memset(obj->f0xe, -1, 6);
	obj->f0xc = -1;
}
