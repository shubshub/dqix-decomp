#include <globaldefs.h>

struct Struct_ov031_02205a38_2 {
	char pad[0xfe];
	signed char unknown_fe_;
};

struct Struct_ov031_02205a38 {
	char pad0[0x64];
	Struct_ov031_02205a38_2* unknown_64_;
	char pad1[0x73 - 0x68];
	signed char unknown_73_;
};

extern "C" int func_ov031_02205ef8(Struct_ov031_02205a38* obj, int b, int c, int d, int e, int f);
extern "C" int func_ov031_02205e60(Struct_ov031_02205a38* obj);

struct Struct_ov031_02205a38_3;
extern "C" int func_ov031_02205ad4(Struct_ov031_02205a38_3* obj, int b, int c, int d, int e, int f);

// USA: func_ov031_02205a38
extern "C" ARM int func_ov031_02205a38(Struct_ov031_02205a38* obj, int b, int c, int d, int e, int f, int flags) {
	Struct_ov031_02205a38_2* sub = obj->unknown_64_;
	bool var1 = ((flags & 2) != 0) && (sub != NULL);
	signed char var2;
	if (var1) {
		var2 = sub->unknown_fe_;
		sub->unknown_fe_ = 1;
	}
	int result;
	if (obj->unknown_73_ == 1) {
		result = func_ov031_02205ef8(obj, b, c, d, e, f);
	} else {
		result = func_ov031_02205ad4((Struct_ov031_02205a38_3*)obj, b, c, d, e, f);
		if (result >= 0) {
			func_ov031_02205e60(obj);
		}
	}
	if (var1) {
		sub->unknown_fe_ = var2;
	}
	return result;
}
