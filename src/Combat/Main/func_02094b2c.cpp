#include <globaldefs.h>
#include "Resource/FontBankLoader.h"

#if defined(jpn)
extern "C" int STD_GetStringLength(const char*);
extern "C" int memcmp(const void*, const void*, unsigned int);
extern "C" void* memset(void*, int, unsigned int);
extern "C" int sprintf(char*, const char*, ...);
#endif

// USA: func_02094b2c
extern "C" ARM void func_02094b2c(FontBankLoader* loader, int index, const char* text, unsigned char arg3,
                               unsigned char arg4) {
#if defined(jpn)
    if (loader->unknown_34_ >= 0) return;
    if (!text) return;
    int length = STD_GetStringLength(text);
    if (!length) return;
    if (length >= 16) return;
    if (loader->unknown_40_ == 1000) {
        int currentLength = STD_GetStringLength(loader->customFontName);
        if (currentLength == length && memcmp(loader->customFontName, text, currentLength) == 0) return;
    }
    memset(loader->customFontName, 0, sizeof(loader->customFontName));
    sprintf(loader->customFontName, text);
    loader->unknown_58_ = 0;
    FontBankLoader_CancelLoads(loader);
    loader->unknown_34_ = index;
    loader->unknown_38_ = 1000;
    loader->unknown_56_ = 0;
    loader->loadStage = 0;
    loader->unknown_61_ = arg3;
    loader->unknown_62_ = arg4;
#endif
}
