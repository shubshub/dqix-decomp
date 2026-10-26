#include <globaldefs.h>

// USA: func_ov000_0215fff4
extern "C" ARM void* func_ov000_0215fff4(void* obj, int limit, int idx) {
    unsigned char* var0 = (unsigned char*)obj + idx;
    if (var0[0x18] <= limit) return 0;
    void* node = *(void**)((char*)obj + idx * 4);
    int i = 0;
    while (i < limit && node != 0) {
        node = *(void**)((char*)node + 0x20);
        i++;
    }
    return node;
}
