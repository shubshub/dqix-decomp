#include <globaldefs.h>
#include "Resource/FontBankLoader.h"

// USA: func_02094b44
extern "C" ARM void* func_02094b44(FontBankLoader* loader, int event) {
    void* table = 0;
#if defined(jpn)
    switch (event) {
    case 8:
        if (loader->unknown_40_ >= 0) table = loader->unknown_4_;
        break;
    case 10:
        if (loader->unknown_3c_ >= 0) table = loader->unknown_0_;
        break;
    case 12:
        if (loader->unknown_40_ >= 0) table = loader->unknown_4_;
        break;
    }
#endif
    return table;
}
