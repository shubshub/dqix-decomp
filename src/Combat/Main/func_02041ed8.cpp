#include <globaldefs.h>

extern char data_020eff93;
extern "C" int STD_GetStringLength(const char* s);
extern "C" int sprintf(char* dst, const char* fmt, ...);

// USA: func_02041ed8
extern "C" ARM int func_02041ed8(char* dst, int a, int b, int c) {
    char* end = dst + STD_GetStringLength(dst);
    return (end + sprintf(end, &data_020eff93, a, b, c)) - dst;
}
