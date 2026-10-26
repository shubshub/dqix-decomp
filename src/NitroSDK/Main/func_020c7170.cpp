#include <globaldefs.h>

typedef char* Type_02001bdc;

extern "C" int func_020c7198(char* dst, unsigned long len, const char* fmt, Type_02001bdc arg3);

// USA: func_020c7170
extern "C" ARM int func_020c7170(char* dst, unsigned long len, const char* fmt, ...) {
    Type_02001bdc var0 = (Type_02001bdc)(((unsigned int)&fmt & ~3u) + 4);
    return func_020c7198(dst, len, fmt, var0);
}
