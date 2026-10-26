#include <globaldefs.h>

struct SetFlagBitStruct {
    char pad[0x50];
    unsigned int f50;
    unsigned short f54;
};

// Main, originally SetFlagBitAndIndex_02086598 (USA 0x02086598, EUR 0x020865a8, JPN 0x02086eb8)
ARM void PartyMemberRecord_SetVocation(struct SetFlagBitStruct* s, int n) {
    s->f54 |= 1 << n;
    s->f50 = n;
}
