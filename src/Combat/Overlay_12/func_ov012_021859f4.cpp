#include <globaldefs.h>

// USA: func_ov012_021859f4
extern "C" ARM int func_ov012_021859f4(void *unused, unsigned char *p, int len, int c) {
	int i = 0;
	while (i < len) {
		if (*p == c) {
			return 1;
		}
		i++;
		p++;
	}
	return 0;
}
