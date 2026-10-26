#include <globaldefs.h>

extern char data_020effd7;

extern "C" int sprintf(char* dst, const char* fmt, ...);
extern "C" ARM int STD_GetStringLength(const char* s);

#if defined(jpn)
#define func_02041fac func_02042638
extern "C" ARM int func_02042638(char* buf, int a, int b);
#endif

// USA: func_02041fac
extern "C" ARM int func_02041fac(char* buf, int a, int b) {
    char* end = buf + STD_GetStringLength(buf);
    return (end + sprintf(end, &data_020effd7, b, a)) - buf;
}
