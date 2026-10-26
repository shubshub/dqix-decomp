#include <globaldefs.h>

extern "C" int func_ov000_02156068(void *a0, int a1, int a2, int a3);

// USA: func_ov024_021d8e18
extern "C" ARM int func_ov024_021d8e18(void **a0, int a1, int a2, int a3, int a4, int a5) {
	if (func_ov000_02156068(*a0, (short)a2, 11, 0) == 0)
		return a5;
	return (int)((float)a5 * 1.25f);
}
