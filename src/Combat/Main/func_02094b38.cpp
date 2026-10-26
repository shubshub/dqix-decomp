#include <globaldefs.h>
#include "Resource/FontBankLoader.h"

#if defined(jpn)
extern "C" void* memset(void*, int, unsigned int);
#endif

// USA: func_02094b38
extern "C" ARM void func_02094b38(FontBankLoader* loader, int arg1) {
#if defined(jpn)
    if (arg1 < 0) return;
    if (loader->unknown_3c_ == arg1) {
        loader->unknown_3c_ = -1;
        loader->unknown_c_ = 0;
        loader->unknown_63_ = 0;
        return;
    }
    if (loader->unknown_40_ == arg1) {
        loader->unknown_40_ = -1;
        loader->unknown_10_ = 0;
        if (arg1 == 1000) memset(loader->customFontName, 0, sizeof(loader->customFontName));
        if (arg1 == 5000) memset(loader->cachedLocationSuffix, 0, sizeof(loader->cachedLocationSuffix));
        loader->unknown_64_ = 0;
    }
#endif
}
