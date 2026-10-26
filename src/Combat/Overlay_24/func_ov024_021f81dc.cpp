#include <globaldefs.h>

struct Struct_02053dc0 { char pad[0x19c]; void* unknown_19c_; };
extern "C" void* func_02053dc0(struct Struct_02053dc0* p);

struct Struct_02053dc0_2 { char data[0x30]; };

struct Struct_ov024_021f81dc {
	char pad0[4];
	short field4;
	char pad6[6];
	int count;
	char pad10[0x114];
	float scale;
	char unknown_128_[0x280];
	struct Struct_02053dc0_2 unknown_3a8_[9];
};

extern "C" void func_ov024_021f9660(void* obj);
extern "C" int func_ov024_021f8628(void* obj, void* p1, void* p2, void* p3);
extern "C" int func_ov024_021f691c(void* obj, unsigned short* outB, void* outA, int key);

// USA: func_ov024_021f81dc
extern "C" ARM int func_ov024_021f81dc(struct Struct_ov024_021f81dc* obj, void* p1, struct Struct_02053dc0* p2, unsigned short* outB) {
	void* result = func_02053dc0(p2);
	if (!result) return (int)result;
	obj->scale = 0.4f;
	func_ov024_021f9660(obj);
	int r = func_ov024_021f691c(&obj->unknown_3a8_[6], outB, result, obj->field4);
	if (r) return r;
	r = func_ov024_021f691c(&obj->unknown_3a8_[5], outB, result, obj->field4);
	if (r) return r;
	if (obj->count >= 4) {
		r = func_ov024_021f691c(&obj->unknown_3a8_[8], outB, result, obj->field4);
		if (r) return r;
	}
	if (obj->count >= 4) {
		r = func_ov024_021f691c(&obj->unknown_3a8_[0], outB, result, obj->field4);
		if (r) return r;
		r = func_ov024_021f691c(&obj->unknown_3a8_[2], outB, result, obj->field4);
		if (r) return r;
	} else {
		r = func_ov024_021f691c(&obj->unknown_3a8_[3], outB, result, obj->field4);
		if (r) return r;
	}
	return func_ov024_021f8628(obj, p1, p2, outB);
}
