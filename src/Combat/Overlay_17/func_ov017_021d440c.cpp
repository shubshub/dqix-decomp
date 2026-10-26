#include <globaldefs.h>

extern "C" void* LinkMessageQueue_GetInstance(void);
extern "C" void func_0205e330(void* a, void* b, int c);

struct Struct_ov017_021d440c {
	unsigned char tag;
	unsigned char pad[3];
	unsigned char val;
	unsigned char pad2[15];
};

// USA: func_ov017_021d440c
extern "C" ARM void func_ov017_021d440c(int a) {
	Struct_ov017_021d440c buf;
	void* p = LinkMessageQueue_GetInstance();
	buf.tag = 0x3c;
	buf.val = (unsigned char)a;
	func_0205e330(p, &buf, 0);
}
