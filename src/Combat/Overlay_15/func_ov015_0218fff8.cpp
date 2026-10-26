#include <globaldefs.h>

struct Struct_ov015_0218fff8 { char pad[0x1c]; unsigned char unknown_1c_; char pad2[0xf]; unsigned char unknown_2c_; char pad3[0x11]; unsigned char unknown_3e_; };

// USA: func_ov015_0218fff8
extern "C" ARM void func_ov015_0218fff8(struct Struct_ov015_0218fff8* o, int val) {
	unsigned char f = o->unknown_1c_;
	if (f != 0 && f != 1)
		return;
	if (o->unknown_3e_ != val) {
		o->unknown_3e_ = val;
		o->unknown_2c_ = 1;
	}
}
