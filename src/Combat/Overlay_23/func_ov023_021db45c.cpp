#include <globaldefs.h>

extern "C" void* func_ov023_021db4e4(void*, int);
extern "C" void func_ov023_021e2acc(void*, int, short*, short*);

struct Struct_ov023_021db45c { char pad[0xac]; short ac; short ae; };
struct Struct_ov023_021db45c_2 { char pad[8]; short f8; short fa; };

// USA: func_ov023_021db45c
extern "C" ARM void func_ov023_021db45c(void* obj, struct Struct_ov023_021db45c* p1, int p2, short* p3, short* p4) {
    struct Struct_ov023_021db45c_2* e = (struct Struct_ov023_021db45c_2*)func_ov023_021db4e4(obj, p2);
    if (e == 0) return;
    short s2 = 0, s0 = 0;
    func_ov023_021e2acc(obj, p2, &s2, &s0);
    short a = s2;
    short b = s0;
    p1->ac = a >> 3;
    p1->ae = b >> 3;
    *p3 = e->f8;
    *p4 = e->fa;
    e->f8 = 0;
    e->fa = 0;
}
