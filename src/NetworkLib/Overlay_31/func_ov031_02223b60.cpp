#include <globaldefs.h>

extern "C" int func_020d4aa8(void);
extern "C" int func_020d4ac8(void);
extern "C" int func_ov031_0223bdb0(int, int, int);

struct Struct_ov031_02223b60 {
	int field0;
	unsigned short field4;
};

struct Struct_ov031_02223b60_2 {
	Struct_ov031_02223b60* field0;
	unsigned char pad4[4];
	signed char field8;
};

extern Struct_ov031_02223b60_2* data_ov031_02250bf8;
extern char data_ov031_022489a4[];

// USA: func_ov031_02223b60
extern "C" ARM void func_ov031_02223b60(void) {
	volatile unsigned short* ime = (volatile unsigned short*)0x4000208;
	int base = 0;
	unsigned short saved = *ime;
	*ime = 0;
	if (func_020d4aa8() != 0x8000) {
		base = func_020d4ac8();
	}

	(void)*ime;
	*ime = saved;
	Struct_ov031_02223b60_2* h = data_ov031_02250bf8;
	int idx = h->field8;
	Struct_ov031_02223b60* c = h->field0;
	unsigned char v = *(unsigned char*)((data_ov031_022489a4 + idx * 4) + base);
	func_ov031_0223bdb0(0, v, (int)c);

	h = data_ov031_02250bf8;
	c = h->field0;
	c->field0 = (c->field0 & 0xfe00ff00) | 0x26 | 0xe50000;
	h = data_ov031_02250bf8;
	c = h->field0;
	c->field4 = (c->field4 & ~0xc00) | 0x800;
}
