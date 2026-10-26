#include <globaldefs.h>

// USA: func_ov031_0221e404
extern "C" THUMB void func_ov031_0221e404(const signed char* key, unsigned char* buf, int len) {
    int i;
    int half = len / 2;
    i = 0;
    if (i < half) {
        unsigned char* p = buf + half;
        do {
            *p ^= key[i];
            i++;
            p++;
        } while (i < half);
    }
}
