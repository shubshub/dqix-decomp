#include <globaldefs.h>

// USA: func_ov015_0219322c
extern "C" ARM void* func_ov015_0219322c(char* base) {
    int i;
    for (i = 0; i < 4; i++) {
        if (*(unsigned char*)(base + i * 8 + 0xe8) == 0)
            return base + 0xe4 + i * 8;
    }
    return NULL;
}
