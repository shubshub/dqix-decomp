#include <globaldefs.h>

struct Struct_ov025_021ded50_2 {
    unsigned short a;
    unsigned short b;
    unsigned short c;
};

extern "C" void func_ov025_021ded84(struct Struct_ov025_021ded50_2* dst, struct Struct_ov025_021ded50_2* src);

struct Struct_ov025_021ded50 {
#if defined(jpn)
    char pad[0x78dc];
#else
    char pad[0x76ec];
#endif
    struct Struct_ov025_021ded50_2 rows[5];
    unsigned short count;
};

// USA: func_ov025_021ded50
extern "C" ARM void func_ov025_021ded50(struct Struct_ov025_021ded50* t, struct Struct_ov025_021ded50_2* src) {
    unsigned short idx = t->count;
    if (idx >= 5) return;

    struct Struct_ov025_021ded50_2* dst = &t->rows[idx];
    t->count = idx + 1;
    func_ov025_021ded84(dst, src);
}
