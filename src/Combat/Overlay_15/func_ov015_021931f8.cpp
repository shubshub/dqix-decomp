#include <globaldefs.h>

// USA: func_ov015_021931f8
extern "C" ARM void* func_ov015_021931f8(char* base) {
    int i;
    for (i = 0; i < 4; i++) {
        if (*(unsigned char*)(base + i * 8 + 0xc8) == 0)
            return base + 0xc4 + i * 8;
    }
    return NULL;
}
