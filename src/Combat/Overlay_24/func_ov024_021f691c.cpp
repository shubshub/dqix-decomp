#include <globaldefs.h>

extern "C" void* func_ov000_02160130(void);
extern "C" void* func_ov000_02160f08(void* obj);
extern "C" void* func_ov024_021f69b4(char* base, int key);
extern "C" void* func_ov000_02171b9c(void* obj, int idx);

struct Struct_ov024_021f691c {
	unsigned short field0;
	signed char field2;
	char pad3;
	float field4;
	char pad8[2];
	unsigned char unknown_a_;
	unsigned char unknown_b_;
};

struct Struct_ov024_021f691c_2 { unsigned short v0; unsigned char v2; unsigned char v3; };

struct Struct_ov024_021f691c_3 {
	char pad0[0x18];
	short unknown_18_;
	char pad1[8];
	signed char unknown_22_;
	char pad2[9];
	short unknown_2c_;
};

// USA: func_ov024_021f691c
extern "C" ARM int func_ov024_021f691c(struct Struct_ov024_021f691c* obj, unsigned short* outB, struct Struct_ov024_021f691c_2* outA, int key) {
	if (obj->field4 > 0.0f) {
		unsigned short field0 = obj->field0;
		if (obj->field2 >= 0) {
			void* work = func_ov000_02160130();
			void* base = func_ov000_02160f08(work);
			struct Struct_ov024_021f691c_3* found = (struct Struct_ov024_021f691c_3*)func_ov024_021f69b4((char*)base, key);
			if (found) {
				found->unknown_22_ = obj->field2;
				struct Struct_ov024_021f691c_3* p = (struct Struct_ov024_021f691c_3*)func_ov000_02171b9c(found, obj->field2);
				if (p) {
					found->unknown_2c_ = p->unknown_18_;
				}
			}
		}
		outA->v0 = field0;
		*outB = field0;
		if (obj->unknown_a_ != 0xff) outA->v3 = obj->unknown_a_;
		if (obj->unknown_b_ != 0xff) outA->v2 = obj->unknown_b_;
		return 1;
	}
	return 0;
}
