#include <globaldefs.h>

// USA: func_020687a4
extern "C" ARM int func_020687a4(int unused, char* obj) {
    int value = *(int*)(obj + 0x8bc);
    return value != 1;
}
