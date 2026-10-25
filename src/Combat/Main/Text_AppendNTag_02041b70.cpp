#include <globaldefs.h>

#if defined(jpn)
#define data_020efeb3 data_020efebb
#endif

int STD_GetStringLength(const char* s);
extern "C" int sprintf(char* dst, const char* fmt, ...);
extern const char data_020efeb3;

// Main, originally AppendNameTag_02041b70 (USA 0x02041b70, EUR 0x02041b80, JPN 0x020421fc)
ARM int Text_AppendNTag(char* dst, int n, const char* name) {
    char* end = dst + STD_GetStringLength(dst);
    return (end + sprintf(end, &data_020efeb3, n, name)) - dst;
}
