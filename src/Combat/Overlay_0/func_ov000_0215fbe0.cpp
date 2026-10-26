#include <globaldefs.h>
#include "Util/Random.h"

extern signed char data_ov000_02182a85[12];

// USA: func_ov000_0215fbe0
extern "C" ARM signed char func_ov000_0215fbe0(struct Random* arg0, int idx) {
    signed char buf[12];
    unsigned char* dst = (unsigned char*)buf;
    unsigned char* src = (unsigned char*)data_ov000_02182a85;
    int cnt = 12;
    do {
        *dst = *src;
        dst++;
        src++;
    } while (--cnt);
    buf[3] = (signed char)NextRandomBetween(arg0, 3, 4);
    buf[0xb] = (signed char)NextRandomBetween(arg0, 6, 8);
    {
        signed char* base = buf;
        if (idx < 0 || idx >= 0xc) {
            return 0;
        }
        return base[idx];
    }
}
