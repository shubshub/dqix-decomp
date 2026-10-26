#include <globaldefs.h>

// USA: func_020d3044
extern "C" ARM int func_020d3044(const unsigned char* a, const unsigned char* b, int n) {
    int i;
    if (n != 0) {
        i = 0;
        if (i < n) {
            do {
                unsigned char var1 = a[i];
                unsigned char cb = b[i];
                if (var1 != cb) return var1 - cb;
                i++;
            } while (i < n);
        }
    }
    return 0;
}
