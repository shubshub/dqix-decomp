#include <globaldefs.h>

// USA: func_ov031_02207e90
extern "C" ARM int func_ov031_02207e90(unsigned char* s, int arg1) {
	unsigned char b1 = s[1];
	unsigned char b0 = *s;
	s += 2;
	unsigned int var2 = b0 * 10 + b1 - 0x210;
	int year;
	if (arg1 == 0x17) {
		if (var2 < 50) {
			year = var2 + 0x7d0;
		} else {
			year = var2 + 0x36c + 0x400;
		}
	} else {
		unsigned char c1 = s[1];
		unsigned char c0 = *s;
		s += 2;
		int var6 = c0 * 10 + c1 - 0x210;
		year = var2 * 100 + var6;
	}
	unsigned char var7 = s[1];
	unsigned char var8 = s[0];
	unsigned char var9 = s[3];
	unsigned char var10 = s[2];
	int month = var8 * 10 + var7 - 0x210;
	int var12 = (year << 16) + (month << 8);
	int day = var10 * 10 + var9 - 0x210;
	return var12 + day;
}
