#include <globaldefs.h>

// USA: func_ov031_0220f368
extern "C" ARM int func_ov031_0220f368(unsigned char *a, unsigned char *b) {
    int i = 0;
    do {
        if (a[i] != b[i]) {
            return 0;
        }
        i++;
    } while (i < 6);
    return 1;
}
