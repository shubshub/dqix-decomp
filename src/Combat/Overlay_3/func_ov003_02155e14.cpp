#include <globaldefs.h>

// USA: func_ov003_02155e14
extern "C" ARM int func_ov003_02155e14(int base, int idx) {
	if (idx <= 0 || idx >= 0xd) {
		return 0;
	}
	return base + (idx - 1) * 0x10;
}
