#include <globaldefs.h>

// A file-local view of PartyMemberData (GameState/PartyMember.h)
struct PartyMemberData {
    char unk_0[0x16c];
    unsigned short levels_[13];
#if defined(jpn)
    char unk_186[0x8b8 - 0x186];
#else
    char unk_186[0x950 - 0x186];
#endif
    int vocation_;
};

// A party member's GameObject, which points at its PartyMemberData
struct PartyMemberObject {
#if defined(jpn)
    char unknown0[0x144];
#else
    char unknown0[0x150];
#endif
    PartyMemberData* data;
};

// Main, originally GetTableValue_0202053c (USA 0x0202053c, EUR 0x0202054c, JPN 0x02020188)
ARM unsigned short GameObject_GetPartyMemberLevel(void* memberIn) {
    PartyMemberData* data = ((PartyMemberObject*)memberIn)->data;
    return data->levels_[data->vocation_];
}
