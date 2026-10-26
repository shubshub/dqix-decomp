#include <globaldefs.h>
#include "Util/Random.h"

extern short data_ov000_02182c14[8];
extern short data_ov000_02182b84[8];
extern "C" int func_ov000_0215eb1c(struct Random* arg0, short* buf, int count, int flag);

// USA: func_ov000_02153d78
extern "C" ARM void func_ov000_02153d78(struct Random* arg0, int arg1, short* out) {
    short buf1[8];
    unsigned short* var1 = (unsigned short*)buf1;
    unsigned short* var2 = (unsigned short*)data_ov000_02182c14;
    int var3 = 8;
    do {
        *var1 = *var2;
        var1++;
        var2++;
    } while (--var3);
    short* p1 = buf1;
    int count = func_ov000_0215eb1c(arg0, p1, 8, 1);

    short buf2[8];
    int var7 = 8;
    unsigned short* var8 = (unsigned short*)buf2;
    unsigned short* src2 = (unsigned short*)data_ov000_02182b84;
    do {
        *var8 = *src2;
        var8++;
        src2++;
    } while (--var7);
    short* p2 = buf2;

    int n = 0;
    for (int i = 0; i < count; i++) {
        if (arg1 != p1[i]) {
            p2[n] = p1[i];
            n++;
        }
    }
    if (n <= 0) {
        *out = (short)arg1;
        return;
    }
    int idx = NextRandomMax(arg0, n);
    *out = p2[idx];
}
