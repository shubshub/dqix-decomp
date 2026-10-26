#include <globaldefs.h>
struct PatternSyntax0218a518;

// Overlay 9, originally FindByteInBuffer0218a888 (USA/EUR 0x0218a888; JPN not identified)
extern "C" ARM int NameFilter_GroupContains(PatternSyntax0218a518* self, unsigned char* members, int memberCount, int token) {
	int i;
	for (i = 0; i < memberCount; i++, members++) {
		if (*members == token) {
			return 1;
		}
	}
	return 0;
}
