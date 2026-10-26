#include <globaldefs.h>

// USA: func_ov031_022089f4
extern "C" ARM int func_ov031_022089f4(unsigned char* data, int count, int stride, unsigned int target) {
	int i = 0;
	if (count > 0) {
		do {
			unsigned int v = (data[0] << 8) + data[1];
			if (stride == 3) {
				v = (v << 8) + data[2];
			}
			if (v == target) {
				return 1;
			}
			i++;
			data += stride;
		} while (i < count);
	}
	return 0;
}
