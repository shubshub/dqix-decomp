#include <globaldefs.h>

// USA: func_02042af4
extern "C" ARM void func_02042af4(int unused, unsigned char* arr, int index) {
    arr[index >> 3] &= ~(1 << (index & 7));
}
