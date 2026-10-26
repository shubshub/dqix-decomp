#include <globaldefs.h>

struct Struct_ov017_021b04c0 {
	char pad0[0xa];
	unsigned char fieldA;
	char pad1[0x21 - 0xb];
	unsigned char unknown_21_;
	unsigned char field22;
	char pad2[0x28 - 0x23];
	int field28;
};

// USA: func_ov017_021b04c0
extern "C" ARM unsigned char func_ov017_021b04c0(Struct_ov017_021b04c0* obj) {
	if (obj->field28 != 0) {
		obj->unknown_21_ = 0;
		obj->field22 = 0;
		return 7;
	}
	return obj->fieldA;
}
