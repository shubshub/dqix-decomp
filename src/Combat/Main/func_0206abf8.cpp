#include <globaldefs.h>
#include "std_library_functions.h"

extern "C" bool func_02044494(void* obj, void* src);

// USA: func_0206abf8
extern "C" ARM int func_0206abf8(void* a, void* src) {
    unsigned short buf;
    int result = 0;
    memcpy(&buf, src, 2);
    if (!func_02044494(a, &buf)) return result;
    switch (buf) {
        case 0xff20: case 0xff21: case 0xff23: case 0xff24:
            result = 1;
            break;
        case 0xff22: case 0xff25:
            result = 2;
            break;
    }
    return result;
}
