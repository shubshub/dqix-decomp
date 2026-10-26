#include <globaldefs.h>

extern "C" int func_ov000_02156068(void *a0, int a1, int a2, int a3);

// USA: func_ov024_021d91c0
extern "C" ARM int func_ov024_021d91c0(void **a0, int a1, int a2, int a3, int a4, int a5) {
	if (func_ov000_02156068(*a0, (short)a2, 10, 0) == 0)
		return a5;
	return (int)((float)a5 * 1.5f);
}
