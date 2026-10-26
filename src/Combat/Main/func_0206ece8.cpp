#include <globaldefs.h>

extern "C" void func_0209953c(unsigned short);

// USA: func_0206ece8
extern "C" ARM void func_0206ece8(int unused, int idx, unsigned char* arr, unsigned int limit) {
    int rem = idx % 2;
    int q = idx / 2;
    if (limit <= q) {
        func_0209953c(0x3e7);
        return;
    }
    {
        unsigned char b = arr[q];
        if (rem != 0) {
            arr[q] = b & 0xf0;
        } else {
            arr[q] = b & 0xf;
        }
    }
}
