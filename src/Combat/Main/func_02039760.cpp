#include <globaldefs.h>

#if defined(jpn)
enum { PartyMember_unknown264 = 0x258 };
#else
enum { PartyMember_unknown264 = 0x264 };
#endif

// USA: func_02039760
extern "C" ARM int func_02039760(void* partyMember) {
    return *(int*)((char*)partyMember + PartyMember_unknown264);
}
