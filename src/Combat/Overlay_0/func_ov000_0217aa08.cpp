#include <globaldefs.h>
#include "std_library_functions.h"

extern "C" int STD_GetStringLength(const char* s);
#if defined(jpn)
extern "C" void __clear(void* buf, int n);
extern char data_ov000_021846f7[];
extern char data_ov000_021846f4[];
#endif

// USA: func_ov000_0217aa08
extern "C" ARM void func_ov000_0217aa08(char* src, char* dst) {
    if (src == NULL || dst == NULL) return;
#if !defined(jpn)
    if (src[0] == 0) return;
#endif
    sprintf(dst, src);
    int len = STD_GetStringLength(dst);
#if defined(jpn)
    if (len <= 2) return;
    int index = len - 2;
    char suffix[3];
    __clear(suffix, 3);
    memcpy(suffix, dst + index, 2);
    if (strcmp(suffix, data_ov000_021846f7) < 0) return;
    if (strcmp(suffix, data_ov000_021846f4) <= 0) {
        dst[index] = 0;
        dst[index + 1] = 0;
    }
#else
    if (len <= 0) return;
    if (dst[len - 1] < 'A') return;
    if (dst[len - 1] > 'Q') return;
    dst[len - 1] = 0;
    if (dst[len - 2] == ' ') dst[len - 2] = 0;
#endif
}
