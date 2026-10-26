#if defined(jpn)
#define R(j,u) (j)
#define data_ov006_02160010 data_ov006_02161364
#else
#define R(j,u) (u)
#endif
#include <globaldefs.h>

extern "C" void* func_ov006_02157368(void* a, int key);
extern "C" void func_ov006_0215f4dc(void* obj);
extern "C" void func_020813ec(void* a, int b);
struct Struct_02080fa8;
extern "C" void func_02080fa8(struct Struct_02080fa8* obj, int id, int value);

struct Struct_ov006_021596f0 {
	unsigned char pad0[R(0xc, 0x14)];
	void* f14;
	unsigned char pad1[0x100 - 0x18];
	unsigned char unknown_100_[1];
	unsigned char pad2[R(0x36e - 0xf9, 0x36e - 0x101)];
	unsigned short unknown_36e_;
	unsigned char pad3[0x38b - 0x370];
	unsigned char unknown_38b_;
	unsigned char pad4[0x394 - 0x38c];
	unsigned short unknown_394_;
};

// USA: func_ov006_021596f0
extern "C" ARM void func_ov006_021596f0(struct Struct_ov006_021596f0* obj) {
	void* p;
	p = func_ov006_02157368(&obj->unknown_100_, 0x50);
	if (p != NULL) ((unsigned char*)p)[0x16] |= 1;
	p = func_ov006_02157368(&obj->unknown_100_, 0x4f);
	if (p != NULL) ((unsigned char*)p)[0x16] &= ~1;
	p = func_ov006_02157368(&obj->unknown_100_, 0xe);
	if (p != NULL) ((unsigned char*)p)[0x16] &= ~1;
	p = func_ov006_02157368(&obj->unknown_100_, 0xf);
	if (p != NULL) ((unsigned char*)p)[0x16] &= ~1;
	p = func_ov006_02157368(&obj->unknown_100_, 0x15);
	if (p != NULL) ((unsigned char*)p)[0x16] &= ~1;
	p = func_ov006_02157368(&obj->unknown_100_, 0x1f);
	if (p != NULL) ((unsigned char*)p)[0x16] &= ~1;
	p = func_ov006_02157368(&obj->unknown_100_, 0x20);
	if (p != NULL) ((unsigned char*)p)[0x16] &= ~1;
	p = func_ov006_02157368(&obj->unknown_100_, 0x21);
	if (p != NULL) ((unsigned char*)p)[0x16] &= ~1;
	p = func_ov006_02157368(&obj->unknown_100_, 0x22);
	if (p != NULL) ((unsigned char*)p)[0x16] &= ~1;
	func_ov006_0215f4dc(obj);
	obj->unknown_394_ |= 8;
	obj->unknown_36e_ = 6;
	{
		int v = obj->unknown_38b_;
		struct Struct_02080fa8* q = (struct Struct_02080fa8*)obj->f14;
		func_02080fa8(q, 0x1f, v);
	}
	func_020813ec(obj->f14, 6);
}
