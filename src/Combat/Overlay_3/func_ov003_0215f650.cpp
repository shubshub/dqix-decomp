#include <globaldefs.h>

struct Struct_ov003_0215f650_3 {
#if defined(jpn)
    char str[0x14];
#else
    char str[0x30];
#endif
};

struct Struct_ov003_0215f650 {
    char bytes[6];
};

struct Struct_ov003_0215f650_2 {
    unsigned char type;
    Struct_ov003_0215f650_3 name;
    Struct_ov003_0215f650 data;
};

// USA: func_ov003_0215f650
extern "C" ARM Struct_ov003_0215f650_2* func_ov003_0215f650(Struct_ov003_0215f650_2* dst, const Struct_ov003_0215f650_2* src) {
    dst->type = src->type;
    dst->name = src->name;
    dst->data = src->data;
    return dst;
}
