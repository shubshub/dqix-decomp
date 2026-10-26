#include <globaldefs.h>

extern "C" ARM int func_020a35e0(unsigned char* obj, unsigned char index);

// USA: func_020a3634
extern "C" ARM int func_020a3634(unsigned char* obj, short* arg1) {
    int i;
    int outCount = 0;
    for (i = 0; i < 4; i++) {
        if (func_020a35e0(obj, i)) {
            arg1[outCount] = i;
            outCount++;
        }
    }
    return outCount;
}
