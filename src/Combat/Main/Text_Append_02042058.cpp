#include <globaldefs.h>

int STD_GetStringLength(const char* s);
extern "C" int sprintf(char* dst, const char* src);

// Main, originally AppendString02042058 (USA 0x02042058, EUR 0x02042068, JPN 0x020426a8)
ARM int Text_Append(char* dst, const char* src) {
    char* end = dst + STD_GetStringLength(dst);
    return (end + sprintf(end, src)) - dst;
}
