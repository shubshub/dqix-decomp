#include <globaldefs.h>

struct Struct_ov024_021f6d80_2 {
	char unk[0xa];
	unsigned short unknown_a_0_ : 7;
	unsigned short field4 : 4;
	unsigned short unknown_b_3_ : 5;
};

struct Struct_ov024_021f6d80 {
	char unk[0x8];
	struct Struct_ov024_021f6d80_2* sub;
	char unk2[0x8];
	float x;
	float y;
	float unknown_1c_;
	float unknown_20_;
};

// USA: func_ov024_021f6d80
extern "C" ARM int func_ov024_021f6d80(struct Struct_ov024_021f6d80* obj) {
	struct Struct_ov024_021f6d80_2* sub = obj->sub;
	if (sub && sub->field4 == 0xb) {
		obj->unknown_1c_ = obj->x * 1.25f;
		obj->unknown_20_ = obj->y * 1.25f;
	}
	return 1;
}
