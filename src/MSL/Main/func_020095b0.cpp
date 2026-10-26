#include <globaldefs.h>

// USA: func_020095b0
extern "C" ARM int func_020095b0(unsigned char *obj, int index) {
    unsigned char *p = obj + 5 + index;
    unsigned char val = *p;
    if (val > 5) return 1;
    if (val < 5) return -1;
    unsigned char len = obj[4];
    unsigned char *q = p + 1;
    unsigned char *end = obj + 5 + len;
    if (q < end) {
        do {
            if (*q != 0) return 1;
            q++;
        } while (q < end);
    }
    index -= 1;
    obj += index;
    return (obj[5] & 1) ? 1 : -1;
}
