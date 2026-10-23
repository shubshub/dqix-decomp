#include <globaldefs.h>

// Overlay 9, originally ToUpperCopy0218a484 (USA/EUR 0x0218a484; JPN not identified)
ARM void NameFilter_CopyUppercase(int self, char *src, char *dst) {
	int c;
	while ((c = *src) != 0) {
		if (c >= 'a' && c <= 'z') {
			c -= 0x20;
			*dst = c;
			c = *dst;
		} else {
			*dst = c;
			c = *dst;
		}
		if (c) {
			src++;
		}
		dst++;
	}
}
