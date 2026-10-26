#include <globaldefs.h>

// USA: func_ov031_0220bb24
extern "C" ARM int func_ov031_0220bb24(unsigned short* arr, int len) {
	while (len != 0 && arr[len - 1] == 0) {
		len--;
	}
	return len;
}
