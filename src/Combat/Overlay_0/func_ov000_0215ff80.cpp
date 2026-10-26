#include <globaldefs.h>

// USA: func_ov000_0215ff80
extern "C" ARM int func_ov000_0215ff80(char* p, int idx) {
	if (idx >= 3) {
		return -1;
	}
	return (idx < 0) ? -1 : *(short*)(p + idx * 2 + 0xe);
}
