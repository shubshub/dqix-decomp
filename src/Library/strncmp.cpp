#include <globaldefs.h>
#include <std_library_functions.h>

ARM int strncmp(const char* lhs, const char* rhs, unsigned int count) {
    if (count != 0) {
        do {
            unsigned char b = *rhs++;
            unsigned char a = *lhs++;
            if (a != b) return a - b;
            if (a == 0) break;
        } while (--count);
    }
    return 0;
}
