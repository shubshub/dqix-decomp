#include <globaldefs.h>
#include "Resource/FontBankLoader.h"

#if defined(jpn)
extern "C" int _Z19STD_GetStringLengthPKc(const char*);
extern "C" int memcmp(const void*, const void*, unsigned int);
extern "C" void* memset(void*, int, unsigned int);
extern "C" int sprintf(char*, const char*, ...);
#endif

// USA: func_02094b2c
ARM void BlankFunction02094b2c(FontBankLoader* loader, int index, const char* text, unsigned char primaryMode,
                               unsigned char supplementalMode) {
#if defined(jpn)
    if (loader->requestedBank >= 0) return;
    if (!text) return;
    int length = _Z19STD_GetStringLengthPKc(text);
    if (!length) return;
    if (length >= 16) return;
    if (loader->supplementalBank == 1000) {
        int currentLength = _Z19STD_GetStringLengthPKc(loader->customFontName);
        if (currentLength == length && memcmp(loader->customFontName, text, currentLength) == 0) return;
    }
    memset(loader->customFontName, 0, sizeof(loader->customFontName));
    sprintf(loader->customFontName, text);
    loader->cachedFontVariant = 0;
    FontBankLoader_CancelLoads(loader);
    loader->requestedBank = index;
    loader->requestedSupplement = 1000;
    loader->dispatchStage = 0;
    loader->loadStage = 0;
    loader->primaryMode = primaryMode;
    loader->supplementalMode = supplementalMode;
#endif
}
