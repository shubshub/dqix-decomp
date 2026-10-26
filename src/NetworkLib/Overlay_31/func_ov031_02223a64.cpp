#include <globaldefs.h>

extern "C" void* func_ov031_0223cf4c(unsigned int len, int align);
extern "C" ARM int func_ov031_0223be44(int a, int b);
extern "C" ARM void* func_ov031_0223e218(void* a, void* b, void* c, int d);
extern "C" void func_ov031_02223b60(void);

struct Struct_ov031_02223a64 {
	int field0;
	unsigned short field4;
};

struct Struct_ov031_02223a64_2 {
	Struct_ov031_02223a64* field0;
	int field4;
	signed char field8;
};

extern Struct_ov031_02223a64_2* data_ov031_02250bf8;
extern unsigned char data_ov031_022489a4[];

// USA: func_ov031_02223a64
extern "C" ARM void func_ov031_02223a64(int index) {
	if (data_ov031_02250bf8 != 0) {
		return;
	}
	Struct_ov031_02223a64_2* h = (Struct_ov031_02223a64_2*)func_ov031_0223cf4c(0xc, 4);
	unsigned char v = *(unsigned char*)&data_ov031_022489a4[index * 4];
	data_ov031_02250bf8 = h;
	h->field8 = (signed char)index;
	int r = func_ov031_0223be44(0, v);

	h = data_ov031_02250bf8;
	h->field0 = (Struct_ov031_02223a64*)r;

	h = data_ov031_02250bf8;
	Struct_ov031_02223a64* c = h->field0;
	c->field0 = (c->field0 & 0xfe00ff00) | 0x26 | 0xe50000;

	h = data_ov031_02250bf8;
	c = h->field0;
	c->field4 = (c->field4 & ~0xc00) | 0x800;

	void* var4 = func_ov031_0223e218(0, (void*)func_ov031_02223b60, 0, 0x78);
	h = data_ov031_02250bf8;
	h->field4 = (int)var4;
}
