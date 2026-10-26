#include <globaldefs.h>

// USA: func_ov000_021719f8
extern "C" ARM int func_ov000_021719f8(int* obj) {
    int flags = obj[0xa];
    int a = (flags & 1) != 0;
    int var2 = a != 0;
    var2 = var2 | ((flags & 0x10) != 0);
    var2 = var2 != 0;
    var2 = var2 | ((flags & 0x80000) != 0);
    var2 = var2 != 0;
    var2 = var2 | ((flags & 8) != 0);
    var2 = var2 != 0;
    return var2;
}
