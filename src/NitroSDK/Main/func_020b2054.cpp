#include <globaldefs.h>

// USA: func_020b2054
extern "C" ARM int func_020b2054(int areaWidth, int arg1) {
    const unsigned int w = (unsigned int)areaWidth;
    const unsigned int h = (unsigned int)arg1;
    const unsigned int w8 = w / 8;
    const unsigned int h8 = h / 8;
    const unsigned int w4 = (w & 4) >> 2;
    const unsigned int h4 = (h & 4) >> 2;
    const unsigned int var6 = ((w & 2) >> 1) + (w & 1);
    const unsigned int var7 = ((h & 2) >> 1) + (h & 1);
    int ret = 0;

    ret += w8 * h8;
    ret += (var6 * 2 + w4) * h8;
    ret += (var7 * 2 + h4) * w8;
    ret += (var6 + w4) * (var7 + h4);

    return ret;
}
