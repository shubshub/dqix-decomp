#include <globaldefs.h>

#if defined(jpn)
enum { Enum_ov023_021fb23c_60 = 0x3a };
#else
enum { Enum_ov023_021fb23c_60 = 0x3c };
#endif

struct Struct_ov023_021fb23c {
    char pad[Enum_ov023_021fb23c_60];
    short a;
    short b;
    short c;
};

// USA: func_ov023_021fb23c
extern "C" ARM void func_ov023_021fb23c(struct Struct_ov023_021fb23c *obj, short a, short b, short c) {
    obj->a = a;
    obj->b = b;
    obj->c = c;
}
