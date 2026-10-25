#include <globaldefs.h>
#include "Resource/FontBankLoader.h"

extern int data_02109400;

#if defined(jpn)
enum { GLOBAL_WORD_OFFSET = 4 };
#else
enum { GLOBAL_WORD_OFFSET = 0 };
#endif

// Main, originally GetGlobal02109400_02094a00 (USA 0x02094a00, EUR 0x02094a10, JPN 0x020952d4)
ARM FontBankLoader* FontBankLoader_GetInstance(void) {
    return *(FontBankLoader**)((char*)&data_02109400 + GLOBAL_WORD_OFFSET);
}
