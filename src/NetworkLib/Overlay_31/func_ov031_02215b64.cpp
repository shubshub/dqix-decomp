#include <globaldefs.h>

extern "C" int func_ov031_02215af4(unsigned int);

// USA: func_ov031_02215b64
extern "C" ARM int func_ov031_02215b64(const unsigned char* input, unsigned char* output, unsigned int count, unsigned int capacity) {
    unsigned int tmp;
    unsigned int tail;
    int k;
    unsigned int var3;
    int i;
    int var5;
    int var6;
    int size = (count * 3) >> 2;
    int j;
    if (capacity >= (count * 3) >> 2) {
        var5 = count & 3;
        var6 = count - var5;
    } else {
        return -1;
    }
    for (i = 0; i < var6; i += 4) {
        var3 = 0;
        for (j = 0; j < 4; j++) {
            var3 |= func_ov031_02215af4(input[i + j]) << ((3 - j) * 6);
        }
        tmp = var3;
        for (k = 0; k < 3; k++) {
            output[(i / 4) * 3 + k] = ((unsigned char*)&tmp)[2 - k];
        }
    }
    if (var5) {
        tail = 0;
        var3 = 0;
        for (j = 0; j < var5; j++) {
            var3 |= func_ov031_02215af4(input[var6 + j]) << ((3 - j) * 6);
            tail |= var3;
        }
        for (k = 0; k < var5; k++) {
            output[(var6 * 3) / 4 + k] = ((unsigned char*)&tail)[2 - k];
        }
    }
    return size;
}
