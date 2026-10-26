#include <globaldefs.h>

extern unsigned char data_020edf2c[];

// USA: func_020d2ac4
extern "C" ARM unsigned short func_020d2ac4(int v) {
    int level;
    if (v < -723) {
        v = -723;
    } else if (v > 0) {
        v = 0;
    }
    unsigned char b = data_020edf2c[v + 0x2d3];
    if (v < -240) {
        level = 3;
    } else if (v < -120) {
        level = 2;
    } else if (v < -60) {
        level = 1;
    } else {
        level = 0;
    }
    return (unsigned short)(b | (level << 8));
}
