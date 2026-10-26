#include <globaldefs.h>

struct Struct_ov003_0215f56c_4 { signed char unknown_0_0_ : 6; signed char unknown_0_6_ : 2; };
struct Struct_ov003_0215f56c { unsigned int pad0 : 10; unsigned int val : 10; unsigned int rest : 12; };
struct Struct_ov003_0215f56c_2 { unsigned int val : 10; unsigned int rest : 22; };

struct Struct_ov003_0215f56c_3 {
	struct Struct_ov003_0215f56c_4 unknown_0_;
	char pad[0x154 - 4];
	struct Struct_ov003_0215f56c unknown_154_;
	struct Struct_ov003_0215f56c_2 unknown_158_;
};

// USA: func_ov003_0215f56c
extern "C" ARM int func_ov003_0215f56c(struct Struct_ov003_0215f56c_3* obj) {
	int result = 0xf;
	if (obj != NULL) {
		if (obj->unknown_0_.unknown_0_0_ >= 0) {
			float a = (float)(unsigned int)obj->unknown_154_.val;
			float b = (float)(unsigned int)obj->unknown_158_.val;
			float ratio = a / b;
			if (ratio <= 0.25f) result = 0xd;
			if (ratio <= 0.08f) result = 0xb;
		}
	}
	return result;
}
