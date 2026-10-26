#include <globaldefs.h>

extern "C" int func_ov031_0223b61c(int, int*, int);
extern int data_ov031_02290d2c[];

// USA: func_ov031_0223bd58
extern "C" ARM void func_ov031_0223bd58(int idx, int val) {
	int local;
	int r = func_ov031_0223b61c(val, &local, 4);
	data_ov031_02290d2c[idx] = r;
}
