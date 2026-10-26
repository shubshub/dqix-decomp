#include <globaldefs.h>

extern "C" void* LinkSession_GetInstance(void);
struct SearchStruct0202c1a4;
extern "C" signed char LinkSession_GetOwnSlot(struct SearchStruct0202c1a4* obj);
extern "C" void* LinkMessageQueue_GetInstance(void);
extern "C" void func_0205e330(void* a, void* b, int c);

// USA: func_ov017_021d079c
extern "C" ARM void func_ov017_021d079c(unsigned char a, unsigned char b, unsigned short c) {
	void* p = LinkMessageQueue_GetInstance();
	void* self = LinkSession_GetInstance();
	unsigned char buf[0x14];
	unsigned char* q = buf + 4;
	q[2] = b;
	buf[0] = 0x99;
	q[0] = a;
	signed char ret = LinkSession_GetOwnSlot((struct SearchStruct0202c1a4*)self);
	q[1] = ret;
	if (q[2] == 0) {
		*(unsigned short*)(q + 4) = c;
	} else if (q[2] == 1) {
		*(unsigned short*)(q + 4) = c;
	}
	func_0205e330(p, buf, 0);
}
