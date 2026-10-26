#include <globaldefs.h>

extern void* data_ov031_0224e53c;
extern "C" void func_ov031_0220d9c8(short a, short b, int c, int d, int e);

// USA: func_ov031_0220d984
extern "C" ARM void func_ov031_0220d984(short p0, int p1, int p2, int p3) {
	short* f = (short*)((char*)data_ov031_0224e53c + 0x2280);
	short v = *f;
	*f = 0;
	func_ov031_0220d9c8(v, p0, p1, p2, p3);
}
