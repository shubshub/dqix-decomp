#include <globaldefs.h>
#include <std_library_functions.h>

ARM char* strrchr(const char* str, int ch) {
    char c = (char)ch;
    char* result = (char*)0;
    char cur = *str;
    char* p = (char*)str + 1;
    if (cur != 0) {
        do {
            if (cur == c) result = p - 1;
            cur = *p++;
        } while (cur != 0);
    }
    if (result != 0) return result;
    if (c != 0) return (char*)0;
    return p - 1;
}
