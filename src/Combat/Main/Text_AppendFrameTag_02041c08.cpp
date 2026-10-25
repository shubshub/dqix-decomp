#include <globaldefs.h>
#if defined(jpn)
#define data_020efee4 data_020efeec
#endif

int STD_GetStringLength(const char* s);
extern "C" int sprintf(char* dst, const char* fmt, ...);
extern "C" const char data_020efee4[];

// Main, originally AppendFrameTag02041c08 (USA 0x02041c08, EUR 0x02041c18, JPN 0x02042294)
ARM int Text_AppendFrameTag(char* dst, int a1, int a2, int a3, int a4, int a5) {
    char* end = dst + STD_GetStringLength(dst);
    return (end + sprintf(end, data_020efee4, a1, a2, a3, a4, a5)) - dst;
}
