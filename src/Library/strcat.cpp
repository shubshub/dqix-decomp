#include <globaldefs.h>
#include <std_library_functions.h>

ARM char* strcat(char* dst, const char* src) {
    char* p = dst;
    char* q;
    while (*p++ != 0) ;
    p--;
    do {
        q = p++;
        *q = *src++;
    } while (*q != 0);
    return dst;
}
