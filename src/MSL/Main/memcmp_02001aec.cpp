#include <globaldefs.h>

// Main, originally func_02001aec (USA/EUR 0x02001aec, JPN 0x02001a08)
extern "C" ARM int memcmp(unsigned char* a, unsigned char* b, int n) {
    if (n != 0) {
        do {
            if (*a++ != *b++) {
                return (a[-1] < b[-1]) ? -1 : 1;
            }
        } while (--n != 0);
    }
    return 0;
}
