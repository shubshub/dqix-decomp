#include <globaldefs.h>

#if defined(jpn)
#define data_020effcb data_020effca
#endif

extern char data_020effcb;

extern "C" int sprintf(char* dst, const char* fmt, ...);
ARM int STD_GetStringLength(const char* s);

// USA: func_02041f70
ARM int AppendFormatted02041f70(char* buf, int a, int b) {
    char* end = buf + STD_GetStringLength(buf);
    return (end + sprintf(end, &data_020effcb, a, b)) - buf;
}
