#include <globaldefs.h>
#include "Resource/FontBankLoader.h"

extern int data_02109400;

#if defined(jpn)
enum { Enum_02094a00_0 = 4 };
#else
enum { Enum_02094a00_0 = 0 };
#endif

// Main, originally GetGlobal02109400_02094a00 (USA 0x02094a00, EUR 0x02094a10, JPN 0x020952d4)
extern "C" ARM FontBankLoader* FontBankLoader_GetInstance(void) {
    return *(FontBankLoader**)((char*)&data_02109400 + Enum_02094a00_0);
}
