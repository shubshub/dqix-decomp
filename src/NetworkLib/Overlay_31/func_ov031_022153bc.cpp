#include <globaldefs.h>

extern "C" unsigned int func_ov031_02207500();
extern "C" void func_ov031_02215690(void* obj);
unsigned long long GetCurrentTimestamp(void);
extern "C" unsigned long long _ll_udiv(unsigned long long arg0, unsigned int arg1, unsigned int flag);

// USA: func_ov031_022153bc
extern "C" ARM int func_ov031_022153bc(char* obj) {
	if ((int)func_ov031_02207500() != 0) {
		func_ov031_02215690(obj);
		unsigned int b = *(unsigned char*)(obj + 0xd0c);
		unsigned int v = (b << 26) >> 30;
		return (v == 1) ? 0xf : 0xd;
	}
	unsigned long long now = GetCurrentTimestamp();
	unsigned long long var3 = *(unsigned long long*)(obj + 0xcb0);
	unsigned long long diff = now - var3;
	unsigned long long var5 = diff << 6;
	unsigned long long var6 = _ll_udiv(var5, 0x1ff6210, 0);
	if (var6 < 10) return 0xc;
	unsigned char idx = *(unsigned char*)(obj + 0xd13);
	*(unsigned char*)(obj + idx * 4 + 0x444) = 1;
	return 0xb;
}
