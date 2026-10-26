#include <globaldefs.h>

extern int data_ov027_021dd8b8[3];

// USA: func_ov027_021da988
extern "C" ARM int func_ov027_021da988(int arg0, unsigned int addr, unsigned int len) {
	int kind = data_ov027_021dd8b8[arg0];
	if (kind == 0) goto case0;
	if (kind == 1) goto case1;
	if (kind != 2) goto defaultCase;
	{
		unsigned int base = 0x27ffe00;
		if (addr < base) goto fail;
		if (addr + len > base + 0x160) goto fail;
		return 1;
	}
case0:
	if (addr < 0x2000000) goto fail;
	if (addr + len > 0x22c0000) goto fail;
	return 1;
case1:
	if (addr >= 0x22c0000) {
		if (addr + len <= 0x2300000) return 1;
	}
	if (addr < 0x2000000) goto fail;
	if (addr + len > 0x2300000) goto fail;
	return 1;
defaultCase:
	return 0;
fail:
	return 0;
}
