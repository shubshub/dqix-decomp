#include <globaldefs.h>

struct Struct020865b0 {
    char pad[0x50];
    int unknown_50_;
};

// Main, originally GetFieldAt0x50 (USA 0x020865b0, EUR 0x020865c0, JPN 0x02086ed0)
extern "C" ARM int PartyMemberRecord_GetVocation(struct Struct020865b0* p) {
    return p->unknown_50_;
}
