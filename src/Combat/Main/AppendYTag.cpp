#include <globaldefs.h>

int STD_GetStringLength(const char* s);
extern "C" int sprintf(char* dst, const char* fmt, ...);
extern const char data_020efe7f;

#if defined(jpn)
#define AppendYTag_02041a5c Font_GetTextWidth
extern "C" ARM int Font_GetTextWidth(char* dst, int y);
#endif

// USA: func_02041a5c
ARM int AppendYTag_02041a5c(char* dst, int y) {
    char* end = dst + STD_GetStringLength(dst);
    return (end + sprintf(end, &data_020efe7f, y)) - dst;
}
