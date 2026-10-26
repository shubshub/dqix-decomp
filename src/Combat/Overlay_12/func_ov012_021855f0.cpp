#include <globaldefs.h>

// USA: func_ov012_021855f0
extern "C" ARM void func_ov012_021855f0(void *unused, char *src, char *dst) {
	char c;
	while ((c = *src) != 0) {
		if (c >= 'a' && c <= 'z') {
			*dst = c - 0x20;
			c = *dst;
		} else {
			*dst = c;
			c = *dst;
		}
		if (c != 0) {
			src++;
		}
		dst++;
	}
}
