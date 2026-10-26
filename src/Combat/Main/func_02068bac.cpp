#include <globaldefs.h>

// USA: func_02068bac
extern "C" ARM int func_02068bac(int unused, char* obj) {
    int value = *(int*)(obj + 0x8b8);
    return value != 0 && value != 1;
}
