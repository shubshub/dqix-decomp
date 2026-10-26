#include <globaldefs.h>

// USA: func_020687b8
extern "C" ARM int func_020687b8(int unused, char* obj) {
    int value = *(int*)(obj + 0x8c0);
    return value != 1;
}
