#include <globaldefs.h>

// USA: func_ov031_0220bc18
extern "C" ARM void func_ov031_0220bc18(unsigned short* dst, unsigned short* src, unsigned int arg2, int count) {
    int i = 0;
    if (count > 0) {
        do {
            arg2 = arg2 + src[i];
            dst[i] = (unsigned short)arg2;
            arg2 = arg2 >> 0x10;
            if (arg2 == 0) break;
            i++;
        } while (i < count);
    }
    if (dst != src) {
        i++;
        if (i < count) {
            do {
                dst[i] = src[i];
                i++;
            } while (i < count);
        }
    }
}
