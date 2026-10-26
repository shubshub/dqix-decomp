#include <globaldefs.h>

extern "C" void* LinkMessageQueue_GetInstance(void);
extern "C" void func_0205e330(void* a, void* b, int c);

struct Struct_ov017_021cc340 {
	unsigned char tag;
	unsigned char pad0[3];
	unsigned char field4;
	unsigned char field5;
	unsigned char field6;
	unsigned char pad1[2];
	unsigned char field9;
	unsigned char pad2[10];
};

// USA: func_ov017_021cc340
extern "C" ARM void func_ov017_021cc340(int a, int b, int c) {
	void* p = LinkMessageQueue_GetInstance();

	Struct_ov017_021cc340 buf;
	buf.tag = 7;
	buf.field6 = a;
	buf.field9 = b;
	buf.field5 = 1;
	buf.field4 = c;
	func_0205e330(p, &buf, 0);
}
