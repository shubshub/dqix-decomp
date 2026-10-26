#include <globaldefs.h>

struct SetBitArrayStruct020865b8 {
    char pad[0x111];
    unsigned char bits[0x1000];
};

// Main, originally SetBitInArray020865b8 (USA 0x020865b8, EUR 0x020865c8, JPN 0x02086ed8)
ARM void PartyMemberRecord_LearnSpell(struct SetBitArrayStruct020865b8* s, int n) {
    s->bits[n / 8] |= 1 << (n % 8);
}
