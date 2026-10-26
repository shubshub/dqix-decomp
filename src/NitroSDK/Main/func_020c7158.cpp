#include <globaldefs.h>

typedef char* Type_02001bdc;

extern "C" int func_020c7198(char* dst, unsigned long len, const char* fmt, Type_02001bdc arg3);

// USA: func_020c7158
extern "C" ARM int func_020c7158(char* dst, const char* fmt, Type_02001bdc arg2) {
    return func_020c7198(dst, 0x7fffffff, fmt, arg2);
}
