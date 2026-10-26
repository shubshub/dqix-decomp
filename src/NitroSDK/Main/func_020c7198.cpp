#include <globaldefs.h>

extern "C" int func_020d3160(char* dst, unsigned long len, const char* fmt, char* arg3);

// USA: func_020c7198
extern "C" ARM int func_020c7198(char* dst, unsigned long len, const char* fmt, char* arg3) {
    return func_020d3160(dst, len, fmt, arg3);
}
