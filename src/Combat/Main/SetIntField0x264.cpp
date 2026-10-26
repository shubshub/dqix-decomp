#include <globaldefs.h>

#if defined(jpn)
enum { PartyMember_unknown264 = 0x258 };
#else
enum { PartyMember_unknown264 = 0x264 };
#endif

// USA: func_02039758
ARM void SetIntField0x264_02039758(void* partyMember, int value) {
    *(int*)((char*)partyMember + PartyMember_unknown264) = value;
}
