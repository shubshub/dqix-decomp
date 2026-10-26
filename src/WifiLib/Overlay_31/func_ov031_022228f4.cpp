#include <globaldefs.h>

extern "C" int func_ov031_022228c0(char*, int);

// USA: func_ov031_022228f4
extern "C" THUMB int func_ov031_022228f4(char* output, const signed char* address) {
    char* cursor = output;
    int i = 0;
    do {
        cursor += func_ov031_022228c0(cursor, *address++);
        if (i < 5) *cursor++ = ':';
        ++i;
    } while (i < 6);
    *cursor = 0;
    return cursor - output;
}
