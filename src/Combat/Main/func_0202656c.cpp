#include <globaldefs.h>
#include "std_library_functions.h"

#if defined(jpn)
#define data_020ef6d0 data_020ef5c0
#endif
extern char data_020ef6d0;

struct Struct_0202656c;

// USA: func_0202656c
extern "C" ARM void func_0202656c(struct Struct_0202656c* p, int val) {
#if defined(jpn)
    enum { Enum_0202656c_1894 = 0x6ba, TextOffset = 0x680 };
#else
    enum { Enum_0202656c_1894 = 0x766, TextOffset = 0x6ec };
#endif
    unsigned char* obj = (unsigned char*)p;
    *(unsigned short*)(obj + Enum_0202656c_1894) = val;
    if (*(unsigned short*)(obj + Enum_0202656c_1894) == 0) return;
    if (*(unsigned short*)(obj + Enum_0202656c_1894) >= 1000) return;
    sprintf((char*)(obj + TextOffset), &data_020ef6d0, val);
}
