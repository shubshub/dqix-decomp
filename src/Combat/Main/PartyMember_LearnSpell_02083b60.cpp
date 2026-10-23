#include <globaldefs.h>

// Main, originally SetBitInArray0x910_02083b60 (USA 0x02083b60, EUR 0x02083b70, JPN 0x0208446c)
ARM void PartyMember_LearnSpell(unsigned char* obj, int index) {
#if defined(jpn)
    unsigned char* p = obj + 0x878;
#else
    unsigned char* p = obj + 0x910;
#endif
    p[index / 8] |= 1 << (index % 8);
}
