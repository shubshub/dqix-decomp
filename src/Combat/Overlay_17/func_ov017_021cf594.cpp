#include <globaldefs.h>

extern "C" void* LinkMessageQueue_GetInstance(void);
extern "C" void func_0205e330(void* a, void* b, int c);

struct Struct_ov017_021cf594 {
	unsigned char tag;
	unsigned char pad0[3];
	unsigned short field4;
	unsigned char field6;
	unsigned char unknown_7_;
	unsigned char pad1[12];
};

// USA: func_ov017_021cf594
extern "C" ARM void func_ov017_021cf594(unsigned short a, int b, int c) {
	Struct_ov017_021cf594 buf;
	void* p = LinkMessageQueue_GetInstance();
	buf.tag = 0x3a;
	buf.field4 = a;
	buf.field6 = b;
	buf.unknown_7_ = c;
	func_0205e330(p, &buf, 0);
}
