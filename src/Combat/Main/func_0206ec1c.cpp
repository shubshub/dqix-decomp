#include <globaldefs.h>

extern "C" void func_0209953c(unsigned short);

// USA: func_0206ec1c
extern "C" ARM int func_0206ec1c(int unused, int idx, unsigned char* arr, unsigned int limit) {
    int rem = idx % 2;
    int q = idx / 2;
    if (limit <= q) {
        func_0209953c(0x3e7);
        return 0;
    }
    {
        int b = arr[q];
        if (rem != 0) {
            return b & 0xf;
        }
        return b >> 4;
    }
}
