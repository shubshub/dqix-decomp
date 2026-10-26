#include <globaldefs.h>

extern "C" int func_ov027_021da988(int idx, unsigned int addr, unsigned int len);
extern int data_ov027_021dd8b8[3];

// USA: func_ov027_021daa34
extern "C" ARM int func_ov027_021daa34(int idx, unsigned int addr, unsigned int len) {
	int kind = data_ov027_021dd8b8[idx];
	if (kind == 0) goto case0;
	if (kind == 1) goto case1;
	if (kind != 2) goto defaultCase;
case0:
	return func_ov027_021da988(idx, addr, len);
case1:
	if (addr < 0x2000000) goto rangeB;
	if (addr >= 0x23fe800) goto rangeB;
	{
		unsigned int end = addr + len;
		if (addr >= 0x2300000) goto rangeC;
		if (end > 0x2300000) return 0;
	rangeC:
		if (end <= 0x2300000) return 1;
		if (end >= 0x23fe800) goto rangeCFail;
		if (len <= 0x40000) return 1;
	rangeCFail:
		return 0;
	}
rangeB:
	{
		unsigned int base = 0x37f8000;
		if (addr < base) goto rangeBFail;
		unsigned int top = base + 0x17000;
		if (addr >= top) goto rangeBFail;
		unsigned int end = addr + len;
		return (end <= top) ? 1 : 0;
	}
defaultCase:
	return 0;
rangeBFail:
	return 0;
}
