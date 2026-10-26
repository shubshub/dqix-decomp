#include <globaldefs.h>

extern "C" ARM int func_020a35e0(unsigned char* obj, unsigned char index);

// USA: func_020a35f8
extern "C" ARM int func_020a35f8(unsigned char* obj) {
    int count = 0;
    int i;
    for (i = 0; i < 4; i++) {
        if (func_020a35e0(obj, i)) {
            count++;
        }
    }
    return count;
}
