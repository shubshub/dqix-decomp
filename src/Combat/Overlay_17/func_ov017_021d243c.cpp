#include <globaldefs.h>

extern "C" void* LinkMessageQueue_GetInstance(void);
extern "C" void func_0205e330(void* a, void* b, int c);

struct Struct_ov017_021d243c {
	unsigned char tag;
	unsigned char pad0[3];
	int field4;
	unsigned char pad1[12];
};

// USA: func_ov017_021d243c
extern "C" ARM void func_ov017_021d243c(int a) {
	Struct_ov017_021d243c buf;
	void* p = LinkMessageQueue_GetInstance();
	buf.tag = 0x1c;
	buf.field4 = a;
	func_0205e330(p, &buf, 0);
}
