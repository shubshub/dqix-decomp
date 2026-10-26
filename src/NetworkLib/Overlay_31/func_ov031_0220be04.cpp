#include <globaldefs.h>

// USA: func_ov031_0220be04
extern "C" ARM void func_ov031_0220be04(unsigned short* arr, int arg1, int i, int count) {
	while (arg1 != 0 && i < count) {
		int v = arg1 + arr[i];
		arr[i] = (unsigned short)v;
		i++;
		arg1 = (unsigned int)v >> 16;
	}
}
