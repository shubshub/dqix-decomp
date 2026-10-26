#include <globaldefs.h>

// USA: func_ov027_021dad84
extern "C" ARM int func_ov027_021dad84(unsigned short *p) {
    unsigned short v = *p++;
    int count = 0;
    if (v != 0) {
        do {
            count++;
            v = *p++;
        } while (v != 0);
    }
    return count;
}
