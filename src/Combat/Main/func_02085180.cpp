#include <globaldefs.h>

// USA: func_02085180
extern "C" ARM int func_02085180(unsigned char* obj) {
    if (*(short*)(obj + 0x2ac) <= 0) return 0;
    return (((unsigned int)*(int*)(obj + 0x2f4) << 25) >> 31) != 0;
}
