#include <globaldefs.h>

// USA: func_ov024_021da644
extern "C" ARM unsigned short func_ov024_021da644(int idx, int a, int b) {
	int inRange = (idx >= 0 && idx <= 3);
	return inRange ? (unsigned short)a : (unsigned short)b;
}
