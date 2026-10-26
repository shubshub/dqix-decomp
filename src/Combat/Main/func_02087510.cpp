#include <globaldefs.h>
#include "std_library_functions.h"

struct Struct_02087510 {
    char pad[0xf2c];
};

// USA: func_02087510
// USA: func_02087510
extern "C" ARM int func_02087510(Struct_02087510* self, char c, void* out) {
    int i;
    for (i = 0; i < 3; i++) {
        if (*(signed char*)((char*)self + 0xf3c + i * 0x14) < 0) {
            memcpy((char*)self + 0xf2c + i * 0x14, out, 0x10);
            *(char*)((char*)self + 0xf3c + i * 0x14) = c;
            return 1;
        }
    }
    return 0;
}
