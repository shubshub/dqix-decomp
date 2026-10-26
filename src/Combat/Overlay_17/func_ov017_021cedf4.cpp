#include <globaldefs.h>

extern "C" void* LinkMessageQueue_GetInstance(void);
extern "C" void func_0205e330(void* a, void* b, int c);

struct Struct_ov017_021cedf4 {
	unsigned char tag;
	unsigned char pad[3];
	int a;
	int b;
	int c;
	int pad2;
};

// USA: func_ov017_021cedf4
extern "C" ARM void func_ov017_021cedf4(int a, int b, int c) {
	void* p = LinkMessageQueue_GetInstance();
	Struct_ov017_021cedf4 buf;
	buf.tag = 0x13;
	buf.a = a;
	buf.b = b;
	buf.c = c;
	func_0205e330(p, &buf, 0);
}
