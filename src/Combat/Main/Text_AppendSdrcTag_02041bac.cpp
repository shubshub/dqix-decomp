#include <globaldefs.h>

#if defined(jpn)
#define data_020efec0 data_020efec8
#endif

int STD_GetStringLength(const char* s);
extern "C" int sprintf(char* dst, const char* fmt, ...);
extern const char data_020efec0;

// Main, originally AppendSourceRectTag_02041bac (USA 0x02041bac, EUR 0x02041bbc, JPN 0x02042238)
ARM int Text_AppendSdrcTag(char* dst, int a, int b, int c, int d, int e) {
    char* end = dst + STD_GetStringLength(dst);
    return (end + sprintf(end, &data_020efec0, a, b, c, d, e)) - dst;
}
