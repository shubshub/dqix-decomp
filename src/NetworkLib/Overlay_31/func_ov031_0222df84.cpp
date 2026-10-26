#include <globaldefs.h>

extern unsigned char* data_ov031_02290c98;
extern "C" ARM void func_ov031_0222df84(void);

// USA: func_ov031_0222e1ac
extern "C" ARM void func_ov031_0222e1ac(void) {
	unsigned char* row;
	int i = 0;
	int j;
	int offset = 0;
	do {
		row = data_ov031_02290c98 + 8 + offset;
		j = 0;
		do {
			unsigned char v = row[j];
			if (v != 0x30 && v != 0x20 && v != 0) break;
			row[j] = (j == 2) ? 0x30 : 0x20;
			j++;
		} while (j < 3);
		i++;
		offset += 3;
	} while (i < 4);
	func_ov031_0222df84();
}
