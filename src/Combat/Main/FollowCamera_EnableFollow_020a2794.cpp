#include <globaldefs.h>

// Main, originally SetField0x238True_020a2794 (USA 0x020a2794, EUR 0x020a27a4, JPN 0x020a450c)
extern "C" ARM void FollowCamera_EnableFollow(void* obj) {
    *(int*)((char*)obj + 0x238) = 1;
}
