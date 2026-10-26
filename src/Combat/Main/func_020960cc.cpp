#include <globaldefs.h>

// USA: func_020960cc
extern "C" ARM void func_020960cc(int unused, unsigned char* arr, int index) {
    if (index > 0xcc) return;
    if (index < 0) return;
    arr[index >> 3] &= ~(unsigned char)(1 << (index & 7));
}
