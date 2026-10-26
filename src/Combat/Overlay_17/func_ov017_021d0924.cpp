#include <globaldefs.h>

extern "C" void LinkSession_GetInstance(void);
extern "C" void* LinkMessageQueue_GetInstance(void);
extern "C" void func_0205e330(void* a, void* b, int c);

// USA: func_ov017_021d0924
extern "C" ARM void func_ov017_021d0924(unsigned char a, unsigned char b, unsigned short c, unsigned short d) {
	void* p = LinkMessageQueue_GetInstance();
	LinkSession_GetInstance();
	unsigned char buf[0x14];
	unsigned char* q = buf + 4;
	buf[0] = 0x9b;
	q[0] = a;
	q[1] = b;
	*(unsigned short*)(q + 2) = c;
	*(unsigned short*)(q + 4) = d;
	func_0205e330(p, buf, 0);
}
