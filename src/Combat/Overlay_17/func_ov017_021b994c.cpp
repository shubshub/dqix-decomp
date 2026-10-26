#include <globaldefs.h>

struct Struct_02061c04_11 {
	char pad[0x12c];
	unsigned int field12c;
	unsigned char unknown_130_;
	unsigned char unknown_131_;
	unsigned char unknown_132_;
	char pad2[0x136 - 0x133];
	unsigned char unknown_136_;
};

// USA: func_ov017_021b994c
extern "C" ARM void func_ov017_021b994c(Struct_02061c04_11* obj) {
	obj->field12c = -1;
	obj->unknown_130_ = 0;
	obj->unknown_131_ = 0;
	obj->unknown_132_ = 0;
	obj->unknown_136_ = 0;
}
