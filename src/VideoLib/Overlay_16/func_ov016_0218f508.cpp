#include <globaldefs.h>

// USA: func_ov016_0218f508
extern "C" ARM int func_ov016_0218f508(void* obj, void* src) {
	char* o = (char*)obj;
	char* s = (char*)src;
	*(void**)(o + 0xc) = s;
	*(int*)(o + 0x4) = *(int*)(s + 0x28) - *(int*)(s + 0x24);
	char* s2 = *(char**)(o + 0xc);
	*(int*)(o + 0x8) = *(int*)(s2 + 0x2c) - *(int*)(s2 + 0x24);
	*(char*)(o + 0x10) = 0;
	return 1;
}
