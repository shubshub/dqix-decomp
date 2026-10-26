#include <globaldefs.h>

// USA: func_ov023_021f6e5c
extern "C" ARM int func_ov023_021f6e5c(void* obj, int idx) {
    int i;
    for (i = 0; i < 0x10; i++) {
        if ((*(unsigned short*)((char*)obj + idx * 2 + 0x2c) & (1 << i)) == 0) {
            return i;
        }
    }
    return -1;
}
