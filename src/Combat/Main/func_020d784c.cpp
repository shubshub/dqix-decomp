#include <globaldefs.h>
#include "std_library_functions.h"

struct Struct_020d784c {
    unsigned int field0;      // 0x0
    unsigned char buf[0x10];  // 0x4
    unsigned short field14;   // 0x14
};

// USA: func_020d784c
extern "C" ARM void func_020d784c(struct Struct_020d784c* obj) {
    obj->field0 = 0;
    obj->field14 = 0;
    memset(obj->buf, -1, 0x10);
}
