#include <globaldefs.h>

int STD_GetStringLength(const char* s);
extern "C" int sprintf(char* dst, const char* fmt, ...);
extern "C" const char data_020eff2f[];

#if defined(jpn)
#define AppendLineYTag02041d48 func_020423d4
extern "C" ARM int func_020423d4(char* dst, int a1, int a2, int a3, int a4);
#endif

// USA: func_02041d48
ARM int AppendLineYTag02041d48(char* dst, int a1, int a2, int a3, int a4) {
    char* end = dst + STD_GetStringLength(dst);
    return (end + sprintf(end, data_020eff2f, a1, a2, a3, a4)) - dst;
}
