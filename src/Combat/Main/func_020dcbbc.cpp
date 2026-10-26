#include <globaldefs.h>

extern "C" int func_020dc920(int a, int b, int c, int d);

// USA: func_020dcbbc
extern "C" ARM int func_020dcbbc(unsigned char* arr, int count, int b, int c, int d) {
    bool found = false;
    for (signed char i = 0; i < count; i++) {
        found = found | func_020dc920(arr[i], b, c, d);
    }
    return found;
}
