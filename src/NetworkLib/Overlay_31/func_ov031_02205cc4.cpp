#include <globaldefs.h>

extern int func_ov031_02205d10;
extern "C" void* func_ov031_02205134(void*, void*, int);
struct Struct_ov031_0220527c;
extern "C" int func_ov031_0220527c(Struct_ov031_0220527c*, void*);

struct Struct_ov031_02205cc4 {
    char pad[0x10];
    unsigned int f10;
    unsigned int f14;
    unsigned int f18;
    unsigned int f1c;
};

// USA: func_ov031_02205cc4
extern "C" ARM int func_ov031_02205cc4(Struct_ov031_0220527c* obj, unsigned int a, unsigned int b, unsigned int c, unsigned int d) {
    Struct_ov031_02205cc4* rec = (Struct_ov031_02205cc4*)func_ov031_02205134(&func_ov031_02205d10, obj, 1);
    rec->f10 = a;
    rec->f14 = b;
    rec->f18 = c;
    rec->f1c = d;
    return func_ov031_0220527c(obj, rec);
}
