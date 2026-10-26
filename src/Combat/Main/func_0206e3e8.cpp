#include <globaldefs.h>

extern short data_020e87c0[];

// USA: func_0206e3e8
extern "C" ARM short func_0206e3e8(int unused, int key) {
    short result = 0;
    short* p = data_020e87c0;
    int i;
    for (i = 0; i < 0x20; i++, p++) {
        if (*p == key) {
            result = (short)i;
            break;
        }
    }
    return result;
}
