#include <globaldefs.h>

// USA: func_02096100
extern "C" ARM int func_02096100(int unused, unsigned char *arr, int idx) {
    unsigned char mask;
    if (idx > 0xcc || idx < 0) {
        return 0;
    }
    mask = 1 << (idx & 7);
    return mask & arr[idx >> 3];
}
