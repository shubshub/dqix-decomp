#include <globaldefs.h>

struct Struct_ov031_02205a38_3 {
	char pad[0x73];
	signed char unknown_73_;
};

extern "C" int func_ov031_02205cc4(Struct_ov031_02205a38_3* obj, int b, int c, int d, int e);
extern "C" int func_ov031_02205b48(Struct_ov031_02205a38_3* obj, int b, int c, int d, int e);

// USA: func_ov031_02205ad4
extern "C" ARM int func_ov031_02205ad4(Struct_ov031_02205a38_3* obj, int b, int c, int d, int e, int f) {
	if (obj->unknown_73_ == 4) {
		return func_ov031_02205cc4(obj, b, c, d, e);
	}
	int result = func_ov031_02205b48(obj, b, c, d, e);
	if (result != -6) {
		return result;
	}
	if ((f & 1) == 0) {
		return result;
	}
	return func_ov031_02205cc4(obj, b, c, d, e);
}
