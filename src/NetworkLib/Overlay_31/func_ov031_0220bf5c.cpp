#include <globaldefs.h>
#include "NitroSDK/Memory.h"

extern "C" int func_ov031_0220bb24(unsigned short*, int);
extern "C" void func_ov031_0220be04(unsigned short*, int, int, int);

// USA: func_ov031_0220bf5c
extern "C" ARM void func_ov031_0220bf5c(unsigned short* output, unsigned short* input, int count) {
    int i;
    int inner;
    int position;
    int outer;
    unsigned int var4;
    int length;
    length = func_ov031_0220bb24(input, count);
    if (count > length * 2) VectorizedMemset(output + length * 2, 0, (count - length * 2) * 2);
    for (i = 0; i < length; i++) {
        position = i * 2;
        if (position >= count) break;
        var4 = input[i] * input[i];
        output[position] = var4;
        if (position == count - 1) break;
        output[position + 1] = var4 >> 16;
    }
    for (outer = 0; outer < length; outer++) {
        for (inner = outer + 1; inner < length && (position = outer + inner) < count; inner++) {
            var4 = input[inner] * input[outer];
            if (var4 <= 0x7fff8000u) {
                func_ov031_0220be04(output, var4 * 2, position, count);
            } else {
                func_ov031_0220be04(output, var4, position, count);
                func_ov031_0220be04(output, var4, position, count);
            }
        }
    }
}
