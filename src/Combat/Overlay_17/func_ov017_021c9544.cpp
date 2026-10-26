#include <globaldefs.h>

extern "C" void* LinkMessageQueue_GetInstance(void);
extern "C" void func_0205e330(void* a, void* b, int c);

// USA: func_ov017_021c9544
extern "C" ARM void func_ov017_021c9544(int a0, int a1, int a2, int a3) {
	void* p = LinkMessageQueue_GetInstance();
	unsigned char buf[0x14];
	unsigned char* b = buf + 4;
	unsigned char var3 = b[3];
	unsigned char var4 = (unsigned char)a1;
	signed char sb = (signed char)a3;
	var3 = (var3 & ~0xf) | (var4 & 0xf);
	b[3] = var3;
	signed char var6 = *(signed char*)&b[3];
	buf[0] = 0x86;
	var6 = (var6 & ~0xf0) | ((sb & 0xf) << 4);
	*(short*)b = (short)a0;
	b[3] = var6;
	func_0205e330(p, buf, 0);
}
