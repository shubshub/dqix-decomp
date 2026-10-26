#include <globaldefs.h>
#include "Resource/FontBankLoader.h"

#if defined(jpn)
extern "C" void* memset(void*, int, unsigned int);
#endif

// USA: func_02094b40
extern "C" ARM void func_02094b40(FontBankLoader* loader) {
#if defined(jpn)
    loader->unknown_3c_ = -1;
    loader->unknown_c_ = 0;
    loader->unknown_63_ = 0;
    loader->unknown_40_ = -1;
    loader->unknown_10_ = 0;
    loader->unknown_64_ = 0;
    memset(loader->customFontName, 0, sizeof(loader->customFontName));
#endif
}
