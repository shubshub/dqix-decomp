#include <globaldefs.h>
#include "Util/Random.h"

extern short data_ov000_02182b14[8];
extern "C" int func_ov000_0215eb1c(struct Random* arg0, short* buf, int count, int flag);

// USA: func_ov000_02153d10
extern "C" ARM void func_ov000_02153d10(struct Random* arg0, short* out) {
    short buf[8];
    unsigned short* dst = (unsigned short*)buf;
    unsigned short* src = (unsigned short*)data_ov000_02182b14;
    int cnt = 8;
    int count;
    int idx;
    do {
        *dst = *src;
        dst++;
        src++;
    } while (--cnt);
    count = func_ov000_0215eb1c(arg0, buf, 8, 1);
    idx = NextRandomMax(arg0, count);
    *out = buf[idx];
}
