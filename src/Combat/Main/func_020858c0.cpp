#include <globaldefs.h>

// USA: func_020858c0
extern "C" ARM float func_020858c0(unsigned char* obj) {
    if (*(short*)(obj + 0x2ac) <= 0) return 1.0f;
    return (float)((*(int*)(obj + 0x2fc) << 8) >> 26) / 10.0f;
}
