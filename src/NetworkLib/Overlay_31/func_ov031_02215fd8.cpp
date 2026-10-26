#include <globaldefs.h>
#include "NitroSDK/Memory.h"

extern void* data_ov031_0224e5d8;

extern "C" int func_ov031_02215fcc(void);
extern "C" void func_020d1ba0(unsigned short* table, unsigned short arg1);
extern "C" int func_020d4f8c(int a, int b, int c, int d);

// USA: func_ov031_02215fd8
extern "C" ARM int func_ov031_02215fd8(void* buf, int b, int c, int d) {
	if (b == 0) return -1;
	data_ov031_0224e5d8 = buf;
	int size = func_ov031_02215fcc();
	VectorizedMemset(data_ov031_0224e5d8, 0, size);
	*(int*)((char*)data_ov031_0224e5d8 + 0x1000 + 0xa90) = 0;
	*(unsigned short*)((char*)data_ov031_0224e5d8 + 0x1a00 + 0x94) = 0;
	func_020d1ba0((unsigned short*)((char*)data_ov031_0224e5d8 + 0x1a00 + 0x96), 0xa001);
	int r = func_020d4f8c((int)data_ov031_0224e5d8, b, c, d);
	return (r == 2) ? 0 : r;
}
