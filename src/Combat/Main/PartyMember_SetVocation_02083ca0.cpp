#include <globaldefs.h>

// Main, originally SetBit0x954StoreIndex0x950_02083ca0 (USA 0x02083ca0, EUR 0x02083cb0, JPN 0x020845b8)
extern "C" ARM void PartyMember_SetVocation(unsigned char* obj, int bit) {
#if defined(jpn)
    *(unsigned short*)(obj + 0x8bc) |= 1 << bit;
#else
    *(unsigned short*)(obj + 0x954) |= 1 << bit;
#endif
#if defined(jpn)
    *(int*)(obj + 0x8b8) = bit;
#else
    *(int*)(obj + 0x950) = bit;
#endif
}
