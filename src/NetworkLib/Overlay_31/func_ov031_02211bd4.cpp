#include <globaldefs.h>
#include "NitroSDK/Memory.h"

struct Struct_ov031_02211bd4 {
	char pad4[4];
	unsigned short field4;
	unsigned short field6;
	unsigned short field8;
	unsigned short unknown_a_;
	unsigned char unknown_c_;
	char unknown_d_[0x10 - 0xd];
	int unknown_10_;
};

struct Struct_ov031_0224e5b4_2 { char pad0[4]; Struct_ov031_02211bd4* field4; };
extern Struct_ov031_0224e5b4_2 data_ov031_0224e5b4;

extern "C" void func_ov031_02207ce0(int);

// USA: func_ov031_02211bd4
extern "C" ARM void func_ov031_02211bd4(Struct_ov031_02211bd4* obj, unsigned short val1, int arg2, int val3) {
	if (data_ov031_0224e5b4.field4 != NULL) return;
	VectorizedMemset(obj, 0, 0x64);
	obj->field8 = val1;
	obj->unknown_a_ = 1;
	obj->field4 = 1;
	obj->field6 = 0;
	obj->unknown_c_ = 0;
	obj->unknown_10_ = 0;
	data_ov031_0224e5b4.field4 = obj;
	func_ov031_02207ce0(val3);
}
