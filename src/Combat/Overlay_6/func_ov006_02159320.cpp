#if defined(jpn)
#define R(j,u) (j)
#define func_ov006_0215f3d8 func_ov006_021607f8
#else
#define R(j,u) (u)
#endif
#include <globaldefs.h>

struct Struct_02080fa8;
extern "C" void func_ov006_02159274(void* obj, unsigned char* a, unsigned char* b, unsigned char* c);
extern "C" void func_ov006_0215f4dc(void* obj);
extern "C" void func_02080fa8(struct Struct_02080fa8* obj, int id, int value);
extern "C" void func_020813ec(void* obj, int flag);

struct Struct_ov006_02159320 {
	unsigned char pad0[R(0xc, 0x14)];
	void* f14;
	unsigned char pad1[0x38b - R(0x10, 0x18)];
	unsigned char unknown_38b_;
	unsigned char pad2[0x430 - 0x38c];
	unsigned char unknown_430_;
};

// USA: func_ov006_02159320
extern "C" ARM void func_ov006_02159320(struct Struct_ov006_02159320* obj) {
	unsigned char buf[3];
	func_ov006_02159274(obj, &buf[1], &buf[2], &buf[0]);
	if (buf[0] > 9) buf[0] = 9;
	if (buf[0] != 0) {
		unsigned char old = obj->unknown_38b_;
		obj->unknown_38b_ = old + 1;
		if (buf[0] < obj->unknown_38b_) obj->unknown_38b_ = buf[0];
		if (old != obj->unknown_38b_) obj->unknown_430_ = 1;
	}
	func_ov006_0215f4dc(obj);
	func_02080fa8((struct Struct_02080fa8*)obj->f14, 0x1f, obj->unknown_38b_);
	func_020813ec(obj->f14, 6);
}
