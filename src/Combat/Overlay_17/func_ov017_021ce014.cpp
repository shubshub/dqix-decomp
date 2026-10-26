#include <globaldefs.h>

extern "C" void* LinkMessageQueue_GetInstance(void);
extern "C" void func_0205e330(void* a, void* b, int c);

struct Struct_ov017_021ce014 {
	unsigned char tag;
	unsigned char pad0[3];
	unsigned short field4;
	unsigned short field6;
	unsigned short field8;
	unsigned char pad1[10];
};

// USA: func_ov017_021ce014
extern "C" ARM void func_ov017_021ce014(int unused, unsigned short b, unsigned short c, unsigned short d) {
	Struct_ov017_021ce014 buf;
	void* p = LinkMessageQueue_GetInstance();
	buf.tag = 0x11;
	buf.field4 = b;
	buf.field6 = c;
	buf.field8 = d;
	func_0205e330(p, &buf, 0);
}
