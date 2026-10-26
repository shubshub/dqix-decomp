#include <globaldefs.h>

// USA: func_0208824c
extern "C" ARM int func_0208824c(unsigned char* obj) {
    int x = *(int*)(obj + 0x14);
    if (x & 1) {
        return 0;
    }
    return (x & 0x1000000) == 0;
}
