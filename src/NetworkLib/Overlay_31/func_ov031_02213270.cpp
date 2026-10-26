#include <globaldefs.h>

struct Struct_ov031_0224e5c4_5 {
	unsigned int field0;
	unsigned int field4;
	unsigned int field8;
	void* fieldc;
	unsigned int field10;
};

extern Struct_ov031_0224e5c4_5 data_ov031_0224e5c4;

struct Struct_ov031_02213270 {
	unsigned int field0;
	int (*fn)(unsigned int, int, int);
	unsigned char flags;
};

extern "C" void* func_ov031_022133f8(unsigned int);

// USA: func_ov031_02213270
extern "C" ARM void func_ov031_02213270(unsigned int mask, int a1, int a2) {
	struct Struct_ov031_02213270* h = (struct Struct_ov031_02213270*)func_ov031_022133f8(1);
	if (h == NULL) return;
	if (!(h->flags & mask)) return;
	h->flags &= ~mask;
	h->fn(mask, a1, a2);
	if (mask == 1) {
		data_ov031_0224e5c4.fieldc = NULL;
	}
}
