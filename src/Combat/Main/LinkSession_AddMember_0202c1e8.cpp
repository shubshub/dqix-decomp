#include <globaldefs.h>

struct SearchStruct;
extern "C" signed char LinkSession_FindAidOfSlot(struct SearchStruct* obj, int value);
extern "C" void LinkSession_UpdateMemberCount(void* obj);

// Main, originally SetSearchFlagBitAt0xc_0202c1e8 (USA 0x0202c1e8, EUR 0x0202c1f8, JPN 0x0202bd98)
extern "C" ARM void LinkSession_AddMember(struct SearchStruct* obj, int value) {
    int idx = LinkSession_FindAidOfSlot(obj, value);
    if (idx < 0) return;
    *((unsigned char*)obj + 0x100c) |= (1 << idx);
    LinkSession_UpdateMemberCount(obj);
}
