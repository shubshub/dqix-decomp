#include <globaldefs.h>

// USA: func_0208569c
extern "C" ARM int func_0208569c(unsigned char* obj) {
    if (*(short*)(obj + 0x2ac) <= 0) return 0;
    return (((unsigned int)*(int*)(obj + 0x2f4) << 3) >> 31) != 0;
}
