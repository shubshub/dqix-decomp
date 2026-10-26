#include <globaldefs.h>

// USA: func_020850fc
extern "C" ARM int func_020850fc(unsigned char* obj) {
    if (*(short*)(obj + 0x2ac) <= 0) return 0;
    return (((unsigned int)*(int*)(obj + 0x2f4) << 28) >> 31) != 0;
}
