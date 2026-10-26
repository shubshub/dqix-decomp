#include <globaldefs.h>

extern "C" void* func_ov023_021e2418(void* obj);
extern "C" ARM void* func_020421b0(int idx);

struct Struct_ov023_021e2550 {
    char pad0[0xc];
    void* unknown_c_;
};

// USA: func_ov023_021e2550
extern "C" ARM void* func_ov023_021e2550(void* obj, int unused, int index) {
    struct Struct_ov023_021e2550* e = (struct Struct_ov023_021e2550*)func_ov023_021e2418(obj);
    if (!e) return e;
    void* entry = func_020421b0((index * 4 + 0x28) & 0xff);
    e->unknown_c_ = entry;
    return entry;
}
