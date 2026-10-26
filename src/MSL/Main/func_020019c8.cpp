#include <globaldefs.h>
#include "std_library_functions.h"

extern "C" ARM int func_020019ac(void* a, void* b);

// USA: func_020019c8
extern "C" ARM int func_020019c8(char* dest, unsigned short* src, int maxLen) {
    int var0 = 0;
    if (dest == 0 || src == 0) return 0;
    char buf[4];
    do {
        unsigned short code = *src;
        if (code == 0) {
            dest[var0] = 0;
            goto done;
        }
        src++;
        int len = func_020019ac(buf, (void*)(int)code);
        if ((unsigned)(var0 + len) > (unsigned)maxLen) goto done;
        strncpy(dest + var0, buf, len);
        var0 += len;
    } while ((unsigned)var0 <= (unsigned)maxLen);
done:
    return var0;
}
