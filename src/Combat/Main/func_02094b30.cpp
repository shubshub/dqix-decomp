#include <globaldefs.h>
#include "Resource/FontBankLoader.h"

#if defined(jpn)
#include "GameState/GameState.h"

enum Enum_02094b30 {
    Enum_02094b30_1000 = 1000,
    Enum_02094b30_5000 = 5000
};

extern "C" int func_020952f4(char* locationSuffix);
extern "C" int memcmp(const void*, const void*, unsigned int);
extern "C" int GameState_GetStoryChapter(char* gameState);
#endif

// USA: func_02094b30
extern "C" ARM void func_02094b30(FontBankLoader* loader, int arg1, int arg2) {
#if defined(jpn)
    if (arg1 < 0 || loader->unknown_34_ >= 0 || loader->unknown_3c_ == arg1) return;
    if (loader->unknown_40_ == arg1) {
        int unchanged = 1;
        char locationSuffix[8] = {};
        switch (loader->unknown_40_) {
        case Enum_02094b30_5000:
            if (memcmp(locationSuffix, loader->cachedLocationSuffix, func_020952f4(locationSuffix)) != 0) {
                unchanged = 0;
            }
            break;
        case Enum_02094b30_1000: {
            int fontVariant = GameState_GetStoryChapter((char*)GameState::GetInstance());
            fontVariant &= 0xff;
            if (fontVariant != loader->unknown_58_) {
                unchanged = 0;
            }
            break;
        }
        }
        if (unchanged) return;
    }
    FontBankLoader_CancelLoads(loader);
    loader->unknown_34_ = arg1;
    loader->unknown_56_ = 0;
    loader->loadStage = 0;
    loader->unknown_61_ = arg2;
#endif
}
