#include <globaldefs.h>
#include "NitroSDK/NetworkIdentity.h"

extern "C" int func_ov031_0221156c(void* p);
extern "C" int func_ov031_022115d0(void* obj);
extern "C" void func_020d1b28(unsigned char* table, unsigned int arg1);
extern "C" unsigned char func_020d1ca0(const unsigned char* table, const unsigned char* data, unsigned int len);

// USA: func_ov031_022457e0
// KEEP-NAME: func_ov031_022457e0
extern "C" ARM unsigned long long func_ov031_022457e0(int unused, Struct_ov031_02291e68 s) {
	if (!func_ov031_0221156c(&s)) return 0;
	int val = func_ov031_022115d0(&s);
	unsigned char table[256];
	struct Struct_ov031_022457e0 { int val; unsigned int magic; } data;
	data.val = val;
	data.magic = 0x5944514a;
	func_020d1b28(table, 7);
	unsigned char var3 = func_020d1ca0(table, (unsigned char*)&data, 8);
	return ((unsigned long long)(var3 & 0x7f) << 32) | (unsigned int)val;
}
