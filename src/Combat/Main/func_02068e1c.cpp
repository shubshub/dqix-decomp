#include <globaldefs.h>
#include "std_library_functions.h"
extern "C" int STD_GetStringLength(const char* s);
// USA: func_02068e1c
extern "C" char* func_02068e1c(char* dst, char* first, char* second, char* third) {
    char* cursor = dst;
    char* a = strstr(dst, first);
    if (!a) {
        goto done;
    }
    {
        char* b = strstr(a, second);
        if (!b) {
            goto done;
        }
        char* c = strstr(b, third);
        if (!c) {
            goto done;
        }
        cursor = a + STD_GetStringLength(first);
        int thirdLen = STD_GetStringLength(third);
        char* out = cursor;
        char* src = cursor;
        for (;;) {
            if (src == b) {
                src = c + thirdLen;
            }
            char ch = *src;
            *out = ch;
            if (ch == 0) {
                break;
            }
            out++;
            src++;
        }
    }
done:
    return cursor;
}
