#include <globaldefs.h>

// Main, originally SetBitInArray0x910_02083b60 (USA 0x02083b60, EUR 0x02083b70, JPN 0x0208446c)
extern "C" ARM void PartyMember_LearnSpell(unsigned char* member, int spell) {
#if defined(jpn)
    unsigned char* learnedSpells = member + 0x878;
#else
    unsigned char* learnedSpells = member + 0x910;
#endif
    learnedSpells[spell / 8] |= 1 << (spell % 8);
}
