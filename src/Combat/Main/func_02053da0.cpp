#include <globaldefs.h>

#if defined(jpn)
enum { Enum_02053da0_412 = 0x190 };
#else
enum { Enum_02053da0_412 = 0x19c };
#endif

struct Struct_02053da0 {
    short f0;
    char f2;
    char f3;
    char f4;
    char pad[3];
    int f8;
};

// USA: func_02053da0
extern "C" ARM void func_02053da0(char* obj, struct Struct_02053da0* p) {
    *(struct Struct_02053da0**)(obj + Enum_02053da0_412) = p;
    p->f0 = 0;
    p->f2 = 0;
    p->f3 = 0;
    p->f4 = 0;
    p->f8 = 0;
}
