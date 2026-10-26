#include <globaldefs.h>

extern "C" int func_ov031_02214520(int);
extern "C" int func_ov031_02214afc(unsigned int);
extern "C" int func_ov031_02214d38(void*);

// USA: func_ov031_02215150
extern "C" ARM int func_ov031_02215150(char* obj) {
	unsigned short v = *(unsigned short*)(obj + 0xd00 + 0x16);
	if (v != 0) {
		if (func_ov031_02214520(2) != 0) {
			obj[0xd11] = (unsigned char)func_ov031_02214afc(0);
			return 5;
		}
	}
	unsigned int nibble = ((unsigned int)(unsigned char)obj[0xd0b] << 24) >> 28;
	if (nibble >= 1) {
		return 6;
	}
	return func_ov031_02214d38(obj);
}
