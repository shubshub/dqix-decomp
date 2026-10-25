#include <globaldefs.h>

int STD_GetStringLength(const char* s);
extern "C" int sprintf(char* dst, const char* fmt, ...);
extern "C" const char data_020eff11[];

#if defined(jpn)
#define AppendLineTag02041cc0 func_0204234c
extern "C" ARM int func_0204234c(char* dst, int a1);
#endif

// USA: func_02041cc0
ARM int AppendLineTag02041cc0(char* dst, int a1) {
    char* end = dst + STD_GetStringLength(dst);
    return (end + sprintf(end, data_020eff11, a1)) - dst;
}
