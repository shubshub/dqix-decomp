#include <globaldefs.h>
#include "std_library_functions.h"

extern "C" int func_ov031_022119d0(int* out, int* arg1);

struct Struct_02245528;
extern "C" void func_ov031_02245528(Struct_02245528* p, int v);

struct Struct_02245478 {
	unsigned char unknown_0_[0x37c];
	void* unknown_37c_;
	int unknown_380_;
	unsigned char unknown_384_[0x394 - 0x384];
	int unknown_394_;
	unsigned char unknown_398_;
};

// USA: func_ov031_02245478
extern "C" ARM void func_ov031_02245478(struct Struct_02245478* obj) {
	int var0;
	int var1;
	int var2 = func_ov031_022119d0(&var0, &var1);
	memset(obj->unknown_37c_, 0, obj->unknown_380_);
	obj->unknown_394_ = -var0;
	switch (var1) {
	case 0:
		obj->unknown_394_ = 0;
		break;
	case 1:
		obj->unknown_394_ = 0;
		break;
	case 6:
		if ((unsigned int)(var2 - 14) <= 1) {
			obj->unknown_398_ = 1;
		}
		break;
	case 7:
		obj->unknown_398_ = 2;
		break;
	default:
		break;
	}
	func_ov031_02245528((Struct_02245528*)obj, 0);
}
