#include <globaldefs.h>

extern "C" void func_ov031_0221ae00(void*);
extern "C" int func_ov031_0221aed8(void*, int);

// USA: func_ov031_0221c208
extern "C" ARM int func_ov031_0221c208(void *s, int x) {
	char buf[0x14];
	func_ov031_0221ae00(buf);
	*(unsigned long long*)((char*)s + 0) = *(unsigned long long*)((char*)s + 8);
	*(unsigned long long*)((char*)s + 8) = *(unsigned long long*)(buf + 8);
	return func_ov031_0221aed8(s, x) != 0;
}
