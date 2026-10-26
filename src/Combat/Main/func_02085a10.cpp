#include <globaldefs.h>

// USA: func_02085a10
extern "C" ARM float func_02085a10(char* obj) {
    if (*(short*)(obj + 0x2ac) <= 0) return 1.0f;
    return (float)((*(int*)(obj + 0x300) << 2) >> 26) / 10.0f;
}
