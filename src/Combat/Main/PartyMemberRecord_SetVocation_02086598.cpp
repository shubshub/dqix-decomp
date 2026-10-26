#include <globaldefs.h>

struct SetFlagBitStruct {
    char pad[0x50];
    unsigned int unknown_50_;
    unsigned short unknown_54_;
};

// Main, originally SetFlagBitAndIndex_02086598 (USA 0x02086598, EUR 0x020865a8, JPN 0x02086eb8)
extern "C" ARM void PartyMemberRecord_SetVocation(struct SetFlagBitStruct* s, int n) {
    s->unknown_54_ |= 1 << n;
    s->unknown_50_ = n;
}
