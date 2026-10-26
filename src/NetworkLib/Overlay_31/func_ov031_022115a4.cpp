#include <globaldefs.h>

// USA: func_ov031_022115a4
extern "C" ARM int func_ov031_022115a4(int *obj) {
	if (obj[10] != 0x41435753) return 0;
	return obj[11] == 0x10000;
}
