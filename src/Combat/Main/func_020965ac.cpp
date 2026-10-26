#include <globaldefs.h>

struct Struct_02065990_3 { unsigned char pad[0xac]; unsigned char tbl[0xcc]; };

// USA: func_020965ac
extern "C" ARM unsigned char func_020965ac(Struct_02065990_3* s, unsigned char idx) {
    if (idx < 0xcc) {
        return s->tbl[idx];
    }
    return 0xff;
}
