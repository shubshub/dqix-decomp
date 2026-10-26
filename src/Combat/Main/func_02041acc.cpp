#include <globaldefs.h>

extern "C" int STD_GetStringLength(const char* s);
extern "C" int sprintf(char* dst, const char* fmt, ...);
extern const char data_020efe91;

#if defined(jpn)
#define func_02041acc func_02042158
extern "C" ARM int func_02042158(char* dst, int w);
#endif

// USA: func_02041acc
extern "C" ARM int func_02041acc(char* dst, int w) {
    char* end = dst + STD_GetStringLength(dst);
    return (end + sprintf(end, &data_020efe91, w)) - dst;
}
