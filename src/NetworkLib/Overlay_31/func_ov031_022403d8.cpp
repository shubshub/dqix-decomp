#include <globaldefs.h>

extern "C" int func_020c7ea0(void* data, int* out, int count);
extern int data_ov031_022918bc;

// USA: func_ov031_022403d8
extern "C" ARM int func_ov031_022403d8(void) {
	int tmp;
	return func_020c7ea0(&data_ov031_022918bc, &tmp, 1);
}
