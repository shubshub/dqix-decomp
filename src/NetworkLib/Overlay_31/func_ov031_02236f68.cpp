#include <globaldefs.h>

struct Struct_ov031_02236f68 { char pad[0x14]; int f14; };
struct Struct_ov031_02290d04_10 { char pad[4]; struct Struct_ov031_02236f68 *p; };
extern struct Struct_ov031_02290d04_10 data_ov031_02290d04;

// USA: func_ov031_02236f68
extern "C" ARM int func_ov031_02236f68(void) {
    return data_ov031_02290d04.p->f14 != 0;
}
