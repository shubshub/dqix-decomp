#include <globaldefs.h>

extern "C" int STD_GetStringLength(const char* s);
extern "C" int sprintf(char* dst, const char* fmt, ...);
extern "C" const char data_020efefb[];

// USA: func_02041c64
extern "C" ARM int func_02041c64(char* dst, int a1, int a2, int a3, int a4, int a5) {
    char* end = dst + STD_GetStringLength(dst);
    return (end + sprintf(end, data_020efefb, a1, a2, a3, a4, a5)) - dst;
}
