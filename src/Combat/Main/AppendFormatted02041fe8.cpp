#include <globaldefs.h>

#if defined(jpn)
#define data_020effec data_020effeb
#endif

extern char data_020effec;

extern "C" int sprintf(char* dst, const char* fmt, ...);
ARM int STD_GetStringLength(const char* s);

// USA: func_02041fe8
ARM int AppendFormatted02041fe8(char* buf, int a) {
    char* end = buf + STD_GetStringLength(buf);
    return (end + sprintf(end, &data_020effec, a)) - buf;
}
