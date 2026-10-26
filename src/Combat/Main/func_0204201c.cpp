#include <globaldefs.h>

extern char data_020efffc;

extern "C" int sprintf(char* dst, const char* fmt, ...);
extern "C" ARM int STD_GetStringLength(const char* s);

// USA: func_0204201c
extern "C" ARM int func_0204201c(char* buf, int a, int b) {
    char* end = buf + STD_GetStringLength(buf);
    return (end + sprintf(end, &data_020efffc, b, a)) - buf;
}
