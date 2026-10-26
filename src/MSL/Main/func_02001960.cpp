#include <globaldefs.h>

// USA: func_02001960
extern "C" ARM int func_02001960(unsigned short* out, const signed char* src, int flag) {
    if (src == 0) return 0;
    if (flag == 0) return -1;
    if (out != 0) {
        *out = (unsigned char)*src;
    }
    if (*src == 0) return 0;
    return 1;
}
