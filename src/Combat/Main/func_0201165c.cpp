#include <globaldefs.h>

#if defined(jpn)
enum { Enum_0201165c_1104 = 0x1d0, Enum_0201165c_1008 = 0x190, Enum_0201165c_1012 = 0x194, Enum_0201165c_1016 = 0x198, Enum_0201165c_1020 = 0x19c, Enum_0201165c_1001 = 0x189, Enum_0201165c_1002 = 0x18a, Enum_0201165c_996 = 0x184, Enum_0201165c_997 = 0x185 };
#else
enum { Enum_0201165c_1104 = 0x450, Enum_0201165c_1008 = 0x3f0, Enum_0201165c_1012 = 0x3f4, Enum_0201165c_1016 = 0x3f8, Enum_0201165c_1020 = 0x3fc, Enum_0201165c_1001 = 0x3e9, Enum_0201165c_1002 = 0x3ea, Enum_0201165c_996 = 0x3e4, Enum_0201165c_997 = 0x3e5 };
#endif
#include "NitroSDK/Memory.h"

struct Struct_0201165c {
    int d;
    int e;
    int f;
    unsigned char g;
    char pad1[3];
    unsigned char h;
};

// USA: func_0201165c
extern "C" ARM void func_0201165c(char* obj, const void* src, int c, struct Struct_0201165c p) {
    VectorizedInvertedMemcpy(src, obj + Enum_0201165c_1104 + 0x6000, 0x1c);
    *(int*)(obj + 0x6000 + Enum_0201165c_1008) = c;
    *(int*)(obj + 0x6000 + Enum_0201165c_1012) = p.d;
    *(int*)(obj + 0x6000 + Enum_0201165c_1016) = p.e;
    *(int*)(obj + 0x6000 + Enum_0201165c_1020) = p.f;
    *(unsigned char*)(obj + 0x6000 + Enum_0201165c_1001) = p.g;
    *(unsigned char*)(obj + 0x6000 + Enum_0201165c_1002) = p.h;
    *(unsigned char*)(obj + 0x6000 + Enum_0201165c_996) = 1;
    *(unsigned char*)(obj + 0x6000 + Enum_0201165c_997) = 1;
}
