#include <globaldefs.h>

int STD_GetStringLength(const char* s);
extern "C" int Font_GetTextWidth(char* label, int extra);
extern "C" int sprintf(char* dst, const char* fmt, ...);
extern char data_020efe91;

// USA: func_02042084
ARM int AppendDotLeaderLabel02042084(char* buffer, char* label, int width, int extra) {
#if defined(jpn)
    int measured = STD_GetStringLength(label);
    measured *= extra;
    int count = ((width - (measured >> 1)) >> 1) + 1;
#else
    int measured = Font_GetTextWidth(label, extra);
    int count = ((width - measured) >> 1) + 1;
#endif
    sprintf(buffer + STD_GetStringLength(buffer), &data_020efe91, count);
    sprintf(buffer + STD_GetStringLength(buffer), label);
    return STD_GetStringLength(buffer);
}
