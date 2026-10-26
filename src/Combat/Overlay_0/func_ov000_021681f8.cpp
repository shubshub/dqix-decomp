#include <globaldefs.h>

// USA: func_ov000_021681f8
extern "C" ARM int func_ov000_021681f8(int id, int count) {
    if (count > 1) {
        if (id == 0xbd || id == 0xbe || id == 0xbf || id == 0x110 || id == 0x155) {
            return 0xb33;
        }
    }
    return 0x1000;
}
