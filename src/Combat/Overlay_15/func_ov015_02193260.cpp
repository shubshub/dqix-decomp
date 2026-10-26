#include <globaldefs.h>

// USA: func_ov015_02193260
extern "C" ARM void* func_ov015_02193260(char* base) {
    int i;
    for (i = 0; i < 4; i++) {
        if (*(unsigned char*)(base + i * 8 + 0x108) == 0)
            return base + 0x104 + i * 8;
    }
    return NULL;
}
