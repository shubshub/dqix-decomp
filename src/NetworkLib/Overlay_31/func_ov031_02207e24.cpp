#include <globaldefs.h>

// USA: func_ov031_02207e24
extern "C" ARM void func_ov031_02207e24(char* dest, const char* src, int count) {
	char* start = dest;
	if (*dest != 0) {
		while (*++dest != 0) {}
		if ((dest - start) >= 0xff) {
			return;
		}
		*dest = ',';
		*(dest + 1) = ' ';
		dest += 2;
	}
	while (count-- != 0 && (dest - start) < 0xff) {
		*dest++ = *src++;
	}
	*dest = 0;
}
