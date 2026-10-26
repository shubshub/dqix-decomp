#include <globaldefs.h>

// USA: func_ov031_022228c0
extern "C" THUMB int func_ov031_022228c0(char* output, int input) {
    char* cursor;
    unsigned char value;
    int index;
    int digit;
    int low;
    cursor = output;
    value = input;
    digit = (value & 0xf0) >> 4;
    index = 0;
    low = value & 0xf;
    do {
        if (digit <= 9) {
            digit += '0';
        } else {
            digit += 'A' - 10;
        }
        index++;
        *cursor++ = digit;
        digit = low;
    } while (index < 2);
    *cursor = 0;
    return cursor - output;
}
