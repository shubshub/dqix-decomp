#include <globaldefs.h>

extern "C" ARM void *func_ov031_0223e218(void *a, void *b, void *c, int d);
extern "C" void func_ov031_02236f88(void);

struct Struct_ov031_02236e60 { char pad[0x14]; int f14; char f18; };
struct Struct_ov031_02290d04_8 { char pad[4]; struct Struct_ov031_02236e60 *p; };
extern struct Struct_ov031_02290d04_8 data_ov031_02290d04;

// USA: func_ov031_02236e60
extern "C" ARM void func_ov031_02236e60(void) {
    data_ov031_02290d04.p->f18 = 1;
    data_ov031_02290d04.p->f14 = (int)func_ov031_0223e218(0, (void*)func_ov031_02236f88, 0, 0x78);
}
