#include <globaldefs.h>

#if defined(jpn)
#define data_020eff74 data_020eff73
#endif

extern char data_020eff74;
int STD_GetStringLength(const char* s);
extern "C" int sprintf(char* dst, const char* fmt, ...);

// Main, originally AppendPaletteTag_02041e70 (USA 0x02041e70, EUR 0x02041e80, JPN 0x020424fc)
ARM int Text_AppendPaletteTag(char* dst, int palette) {
    char* end = dst + STD_GetStringLength(dst);
    return (end + sprintf(end, &data_020eff74, palette)) - dst;
}
