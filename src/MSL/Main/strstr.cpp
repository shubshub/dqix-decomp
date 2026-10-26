#include <globaldefs.h>

// KEEP-NAME: the ROM symbol is the C library name, not a func_ tag.
// USA: func_0200423c
extern "C" ARM char* strstr(const char* arg0, const char* arg1) {
    unsigned char first;
    if (arg1 == 0 || (first = *(const unsigned char*)arg1) == 0) {
        return (char*)arg0;
    }

    unsigned char h = *(const unsigned char*)arg0;
    char* p = (char*)arg0 + 1;
    if (h != 0) {
        do {
        if (h == first) {
            const unsigned char* q = (const unsigned char*)p;
            const unsigned char* n = (const unsigned char*)arg1 + 1;
            unsigned char var5;
            unsigned char hc;
            do {
                var5 = *n++;
                hc = *q++;
            } while (hc == var5 && hc != 0);
            if (var5 == 0) {
                return p - 1;
            }
        }
            h = *(const unsigned char*)p++;
        } while (h != 0);
    }
    return 0;
}
