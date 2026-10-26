#include <globaldefs.h>

extern "C" void func_ov031_0220bc18(unsigned short* dst, unsigned short* src, int arg2, int count);

// USA: func_ov031_0220bc7c
extern "C" ARM void func_ov031_0220bc7c(unsigned short* arr, int count) {
	int i = 0;
	if (count > 0) {
		do {
			arr[i] = ~arr[i];
			i++;
		} while (i < count);
	}
	func_ov031_0220bc18(arr, arr, 1, count);
}
