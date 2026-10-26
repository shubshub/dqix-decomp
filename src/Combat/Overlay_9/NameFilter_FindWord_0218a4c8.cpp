#include <globaldefs.h>
extern "C" int memcmp(int val, int key, int field5);

// Overlay 9, originally FindMatch0218a4c8 (USA/EUR 0x0218a4c8; JPN not identified)
extern "C" ARM int NameFilter_FindWord(int self, int word, int text, int length, int count) {
	int i;
	for (i = 0; i < count; i++, text++) {
		if (memcmp(word, text, length) == 0) {
			return 1;
		}
	}
	return 0;
}
