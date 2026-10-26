#include <globaldefs.h>
#include <std_library_functions.h>

ARM char* strchr(const char* str, int ch) {
    char cur = *str++;
    char c = (char)ch;
    if (cur != 0) {
        do {
            if (cur == c) return (char*)(str - 1);
            cur = *str++;
        } while (cur != 0);
    }
    if (c != 0) return (char*)0;
    return (char*)(str - 1);
}
