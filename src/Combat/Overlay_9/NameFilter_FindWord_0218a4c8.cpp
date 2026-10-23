#include <globaldefs.h>
extern "C" int func_02001aec(int val, int key, int field5);

// Overlay 9, originally FindMatch0218a4c8 (USA/EUR 0x0218a4c8; JPN not identified)
ARM int NameFilter_FindWord(int self, int word, int text, int length, int count) {
	int i;
	for (i = 0; i < count; i++, text++) {
		if (func_02001aec(word, text, length) == 0) {
			return 1;
		}
	}
	return 0;
}
