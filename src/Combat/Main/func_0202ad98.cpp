#include <globaldefs.h>

typedef char* Type_02001bdc;

extern "C" int func_02003c80(char* buf, int size, const char* fmt, Type_02001bdc arg3);
extern "C" void func_0202ad4c(int a, int b, int c, char* buf);

// USA: func_0202ad98
extern "C" ARM void func_0202ad98(int a, int b, int c, const char* fmt, ...) {
    char buf[0x21];
    Type_02001bdc var1 = (Type_02001bdc)(((unsigned int)&fmt & ~3u) + 4);
    func_02003c80(buf, 0x21, fmt, var1);
    func_0202ad4c(a, b, c, buf);
}
