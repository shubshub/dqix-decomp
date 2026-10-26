#include <globaldefs.h>

extern "C" void* LinkMessageQueue_GetInstance(void);
extern "C" void func_0205e330(void* a, void* b, int c);

struct Struct_ov017_021d23bc {
	unsigned char tag;
	unsigned char pad0[3];
	unsigned short field4;
	unsigned char pad1[14];
};

// USA: func_ov017_021d23bc
extern "C" ARM void func_ov017_021d23bc(unsigned short a) {
	Struct_ov017_021d23bc buf;
	void* p = LinkMessageQueue_GetInstance();
	buf.tag = 0x9e;
	buf.field4 = a;
	func_0205e330(p, &buf, 0);
}
