#include <globaldefs.h>

// USA: func_ov031_02242f14
extern "C" ARM int func_ov031_02242f14(const char* p, int len) {
    int digits = 0;
    int accum = 0;
    if (len-- != 0) {
        do {
            signed char c = *p;
            if (c != ' ' && c >= '0' && c <= '9') {
                accum = accum * 10 + c;
                accum -= '0';
                digits++;
                if (digits > 9) return -1;
            }
            p++;
        } while (len-- != 0);
    }
    if (digits == 0) accum = -1;
    return accum;
}
