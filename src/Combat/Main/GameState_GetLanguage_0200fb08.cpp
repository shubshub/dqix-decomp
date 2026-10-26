#include <globaldefs.h>
#include "NitroSDK/OSLanguage.h"

extern "C" void OS_GetOwnerInfo(void* out);

struct Struct0200fb08 { unsigned char pad[5]; unsigned char language; };

// USA: GameState_GetLanguage
// EUR: GameState_GetLanguage
// Main, originally NormalizeField5_0200fb08 (USA 0x0200fb08, EUR 0x0200fb10; JPN not identified)
extern "C" ARM unsigned char GameState_GetLanguage(Struct0200fb08* gameState) {
    unsigned char ownerInfo[0x54];
    unsigned char ownerLanguage;
    OS_GetOwnerInfo(ownerInfo);
    ownerLanguage = ownerInfo[0];
    gameState->language = ownerLanguage;
#if defined(eur)
    if (ownerLanguage != OSLanguage_French && ownerLanguage != OSLanguage_German &&
        ownerLanguage != OSLanguage_Italian && ownerLanguage != OSLanguage_Spanish) gameState->language = 1;
#else
    if (ownerLanguage != OSLanguage_French && ownerLanguage != OSLanguage_Spanish) gameState->language = 1;
#endif
    return gameState->language;
}
