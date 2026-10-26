#include <globaldefs.h>

// USA: func_ov031_0221b158
extern "C" ARM unsigned char func_ov031_0221b158(unsigned char* p) {
    int cnt;
    int i = 0;
    cnt = 0;
    do {
        int j = 0;
        unsigned char b = p[i];
        do {
            if ((b >> j) & 1) cnt++;
            j++;
        } while (j < 8);
        i++;
    } while (i < 4);
    return (unsigned char)cnt;
}
