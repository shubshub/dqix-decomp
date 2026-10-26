#include <globaldefs.h>

// USA: func_02085670
extern "C" ARM int func_02085670(unsigned char* obj) {
    if (*(short*)(obj + 0x2ac) <= 0) return 0;
    return (((unsigned int)*(int*)(obj + 0x2f4) << 4) >> 31) != 0;
}
