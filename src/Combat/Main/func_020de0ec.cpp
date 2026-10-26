#include <globaldefs.h>
#include "std_library_functions.h"

struct Struct_020de0ec {
    unsigned char pad[0x24];
    unsigned char field24;
};

// USA: func_020de0ec
extern "C" ARM void func_020de0ec(struct Struct_020de0ec* obj) {
    int r = rand() % 10000;
    obj->field24 = 0;
    if (r < 25) {
        obj->field24 |= 4;
        return;
    }
    if (r < 200) {
        obj->field24 |= 2;
    } else {
        obj->field24 |= 1;
    }
}
