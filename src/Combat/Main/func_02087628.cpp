#include <globaldefs.h>
#include "std_library_functions.h"

// USA: func_02087628
extern "C" ARM void func_02087628(char* base) {
    int i;
    for (i = 0; i < 3; i++) {
        memset(base + 0xf2c + i * 0x14, 0, 0x14);
        *(char*)(base + 0xf3c + i * 0x14) = -1;
    }
}
