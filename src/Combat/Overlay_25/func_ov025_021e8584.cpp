#include <globaldefs.h>

struct Struct_0202e95c;

struct Struct_ov025_021e8584 {
    char pad[0x8];
    short a;
    unsigned short b;
};

extern "C" void* func_ov000_02160130(void);
extern "C" void* func_ov000_02160f14(void* w);
extern "C" void func_0202e95c(Struct_0202e95c*, short, unsigned short);

// USA: func_ov025_021e8584
extern "C" ARM int func_ov025_021e8584(struct Struct_ov025_021e8584* obj) {
    void* w = func_ov000_02160130();
    func_0202e95c((struct Struct_0202e95c*)func_ov000_02160f14(w), obj->a, obj->b);
    return 1;
}
