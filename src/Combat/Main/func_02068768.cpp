#include <globaldefs.h>

// USA: func_02068768
extern "C" ARM int func_02068768(int unused, char* obj) {
    return *(int*)(obj + 0x8b0) != 1;
}
