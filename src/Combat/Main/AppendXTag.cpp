#include <globaldefs.h>

#if defined(jpn)
#define data_020efe78 data_020efe80
#endif

int STD_GetStringLength(const char* s);
extern "C" int sprintf(char* dst, const char* fmt, ...);
extern const char data_020efe78;

// USA: func_02041a28
ARM int AppendXTag_02041a28(char* dst, int x) {
    char* end = dst + STD_GetStringLength(dst);
    return (end + sprintf(end, &data_020efe78, x)) - dst;
}
