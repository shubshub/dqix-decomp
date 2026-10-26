#include <globaldefs.h>

extern "C" void* LinkMessageQueue_GetInstance(void);
extern "C" void func_0205e330(void* a, void* b, int c);

struct Struct_ov017_021cf4b0 {
	unsigned char tag;
	unsigned char pad[3];
	unsigned char a;
	unsigned char b;
	unsigned char pad2[14];
};

// USA: func_ov017_021cf4b0
extern "C" ARM void func_ov017_021cf4b0(int a, int b) {
	void* p = LinkMessageQueue_GetInstance();
	Struct_ov017_021cf4b0 buf;
	buf.tag = 0x39;
	buf.a = (unsigned char)a;
	buf.b = (unsigned char)b;
	func_0205e330(p, &buf, 0);
}
