#include <globaldefs.h>

extern "C" ARM int func_020dd11c(unsigned int a, unsigned int b);
extern unsigned char data_020ee700[];

// USA: func_020dd19c
extern "C" ARM int func_020dd19c(unsigned int p0, int p1) {
    int found = 0;
    for (unsigned char i = 0; i < 4; i++) {
        unsigned int idx = func_020dd11c(p0, i);
        if (idx != 0 && idx <= 0xe) {
            if (data_020ee700[idx] == p1) {
                found = 1;
                break;
            }
        }
    }
    return found;
}
