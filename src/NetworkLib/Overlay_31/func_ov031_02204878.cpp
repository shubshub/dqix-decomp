#include <globaldefs.h>

// USA: func_ov031_02204878
extern "C" ARM char* func_ov031_02204878(char* p) {
    unsigned char c = *p++;
    if (c != 0) {
        do {
            if ((c & 0xc0) == 0xc0) {
                return p + 1;
            }
            p += c;
            c = *p++;
        } while (c != 0);
    }
    return p;
}
