#include <globaldefs.h>
#if defined(jpn)
#define func_02029140 func_02028a20
#endif

typedef char* Type_02001bdc;

extern "C" int func_02003c80(char* buf, int size, const char* fmt, Type_02001bdc arg3);
extern "C" void func_02029140(int a, int b, char* buf);

// USA: func_020290e8
extern "C" ARM void func_020290e8(int a, int b, const char* fmt, ...) {
    char buf[0x100];
    Type_02001bdc var1 = (Type_02001bdc)(((unsigned int)&fmt & ~3u) + 4);
    func_02003c80(buf, 0x100, fmt, var1);
    buf[0xff] = 0;
    func_02029140(a, b, buf);
}
