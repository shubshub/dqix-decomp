#include <globaldefs.h>

extern char data_020effbd;
extern "C" int STD_GetStringLength(const char* s);
extern "C" int sprintf(char* dst, const char* fmt, ...);

// USA: func_02041f24
extern "C" ARM int func_02041f24(char* dst, int a, int b, int c) {
    char* end = dst + STD_GetStringLength(dst);
    return (end + sprintf(end, &data_020effbd, a, b, c)) - dst;
}
