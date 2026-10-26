#include <globaldefs.h>

// USA: func_ov000_0218158c
extern "C" ARM int func_ov000_0218158c(void* obj, int n) {
    int mask = *(int*)((char*)obj + 0x68);
    int count = 0;
    int bit;
    for (bit = 0; bit < 0xc; bit++) {
        if (mask & (1 << bit)) {
            if (count == n) return bit;
            count++;
        }
    }
    return 0;
}
