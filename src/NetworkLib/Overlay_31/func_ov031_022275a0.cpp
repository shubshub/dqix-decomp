#include <globaldefs.h>

extern int data_ov031_02250c0c;

// USA: func_ov031_022275a0
extern "C" ARM int func_ov031_022275a0(void) {
	unsigned char type = *(unsigned char*)&data_ov031_02250c0c;
	if (type == 6) return 0x38;
	if (type == 1) {
		unsigned int flags = *(unsigned int*)((char*)&data_ov031_02250c0c + 8);
		if (((flags >> 4) & 2) == 0) return 0x37;
	}
	return (type + 0x31) & 0xff;
}
