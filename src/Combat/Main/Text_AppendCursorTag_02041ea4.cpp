#include <globaldefs.h>

#if defined(jpn)
#define data_020eff87 data_020eff86
#endif

extern char data_020eff87;
int STD_GetStringLength(const char* s);
extern "C" int sprintf(char* dst, const char* fmt, ...);

// Main, originally AppendCursorTag_02041ea4 (USA 0x02041ea4, EUR 0x02041eb4, JPN 0x02042530)
ARM int Text_AppendCursorTag(char* dst, int cursor) {
    char* end = dst + STD_GetStringLength(dst);
    return (end + sprintf(end, &data_020eff87, cursor)) - dst;
}
