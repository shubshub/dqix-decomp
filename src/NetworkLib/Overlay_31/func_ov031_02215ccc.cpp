#include <globaldefs.h>

// USA: func_ov031_02215ccc
extern "C" ARM int func_ov031_02215ccc(int c) {
	int v = c >> 2;
	if (!(c & 2)) v += 0x19;
	return v & 0xff;
}
