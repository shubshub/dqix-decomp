#include <globaldefs.h>

// USA: func_ov000_0215fe2c
extern "C" ARM void* func_ov000_0215fe2c(void* obj, int idx) {
    if (*((unsigned char*)obj + 0x1f) <= idx) return 0;
    void* node = *(void**)((char*)obj + 8);
    int i = 0;
    while (i < idx && node != 0) {
        node = *(void**)((char*)node + 4);
        i++;
    }
    return node;
}
