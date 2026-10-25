#include <globaldefs.h>
#include "GameState/GameState.h"

// Main, originally GetPtrField0x2a04_02010828 (USA 0x02010828, EUR 0x02010838, JPN 0x02010684)
ARM void* GameState_GetParty(GameState* battleStruct) {
#if defined(jpn)
    return (char*)battleStruct + 0x27a4;
#else
    return (char*)battleStruct + 0x2a04;
#endif
}
