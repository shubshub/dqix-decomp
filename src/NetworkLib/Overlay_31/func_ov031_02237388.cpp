#include <globaldefs.h>

struct Struct_ov031_02237388 { unsigned char pad[0x18]; unsigned char field18; };
struct Struct_ov031_02290d04_16 { char pad[4]; struct Struct_ov031_02237388 *p; };
extern struct Struct_ov031_02290d04_16 data_ov031_02290d04;

// USA: func_ov031_02237388
extern "C" ARM int func_ov031_02237388(void) {
    if (data_ov031_02290d04.p == 0) {
        return 1;
    }
    return data_ov031_02290d04.p->field18 == 0;
}
