#include <globaldefs.h>

// Main, originally SetField0x238False_020a27a0 (USA 0x020a27a0, EUR 0x020a27b0, JPN 0x020a4518)
ARM void FollowCamera_DisableFollow(void* obj) {
    *(int*)((char*)obj + 0x238) = 0;
}
