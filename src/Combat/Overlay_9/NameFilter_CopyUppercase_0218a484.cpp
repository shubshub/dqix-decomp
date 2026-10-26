#include <globaldefs.h>

// Overlay 9, originally ToUpperCopy0218a484 (USA/EUR 0x0218a484; JPN not identified)
extern "C" ARM void NameFilter_CopyUppercase(int self, char *src, char *dst) {
	int character;
	while ((character = *src) != 0) {
		if (character >= 'a' && character <= 'z') {
			character -= 'a' - 'A';
			*dst = character;
			character = *dst;
		} else {
			*dst = character;
			character = *dst;
		}
		if (character) {
			src++;
		}
		dst++;
	}
}
