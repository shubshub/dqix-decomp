#include <globaldefs.h>

// USA: func_0208902c
extern "C" ARM void func_0208902c(unsigned char* obj, int val) {
    unsigned int x = *(unsigned int*)(obj + 0x14);
    int var1 = 0;
    if (x & 0x4) {
        var1 = 1;
    }
    *(unsigned int*)(obj + 0x14) = 0;
    *(unsigned int*)(obj + 0x18) = 0;
    if (var1) {
        *(unsigned int*)(obj + 0x14) |= 0x4;
    }
    *(unsigned short*)obj = val;
}
