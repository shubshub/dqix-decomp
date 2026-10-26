#include <globaldefs.h>

// Main, originally ResetAndCopyShorts0x1c_020863c4 (USA 0x020863c4, EUR 0x020863d4, JPN 0x02086ce4)
extern "C" ARM void PartyMember_RestoreHpMp(unsigned char* obj) {
    *(int*)(obj + 0x18) = 0;
    *(unsigned short*)(obj + 0x1c) = *(unsigned short*)(obj + 0x6c);
    *(unsigned short*)(obj + 0x1e) = *(unsigned short*)(obj + 0x6e);
}
