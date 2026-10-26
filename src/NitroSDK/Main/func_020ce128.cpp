#include <globaldefs.h>

struct Struct_021117ec { unsigned char pad[0x1c]; int lock; };
extern struct Struct_021117ec data_021117ec;

// USA: func_020ce128
extern "C" ARM int func_020ce128(void) {
    if (data_021117ec.lock != 0) {
        return 0;
    }
    data_021117ec.lock = 1;
    return 1;
}
