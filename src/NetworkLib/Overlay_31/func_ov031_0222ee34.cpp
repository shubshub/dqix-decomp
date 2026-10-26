#include <globaldefs.h>

extern "C" char* func_ov031_02235c70(void);
extern "C" void func_ov031_02227520(int*, int*);
extern unsigned char data_ov031_02290ca0;

// USA: func_ov031_0222ee34
extern "C" ARM void func_ov031_0222ee34(void) {
	func_ov031_02235c70();
	int idx;
	func_ov031_02227520(NULL, &idx);
	if (idx != 0) return;
	*(unsigned short*)((char*)&data_ov031_02290ca0 + 4) = 0;
	(&data_ov031_02290ca0)[0] = 0;
	(&data_ov031_02290ca0)[2] = 0;
}
