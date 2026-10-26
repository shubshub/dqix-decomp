#include <globaldefs.h>

extern "C" void* func_ov011_021849c8(void* a);
extern "C" void* func_ov023_021f6880(void* a, int b);

struct Struct_ov023_021f65d4 {
    char pad0[0xc];
    unsigned char f0xc;
};

// USA: func_ov023_021f65d4
extern "C" ARM void func_ov023_021f65d4(void* a, int b, int c) {
    void* r = func_ov011_021849c8(a);
    Struct_ov023_021f65d4* obj = (Struct_ov023_021f65d4*)func_ov023_021f6880(r, b);
    if (obj != 0) {
        obj->f0xc |= c;
    }
}
