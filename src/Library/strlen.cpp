#include <globaldefs.h>
#include <std_library_functions.h>

ARM unsigned int strlen(const char* str) {
    unsigned int len = -1;
    char c;
    do {
        c = *str++;
        len++;
    } while (c != 0);
    return len;
}
