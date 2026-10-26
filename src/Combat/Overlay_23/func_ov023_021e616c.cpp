#include <globaldefs.h>

// USA: func_ov023_021e616c
extern "C" ARM void func_ov023_021e616c(char* obj) {
    int i;
    for (i = 0; i < 0xa; i++) {
        *(short*)(obj + i * 0xac + 0x2) = -1;
    }
}
