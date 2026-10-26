#include <globaldefs.h>

// USA: func_02068790
extern "C" ARM int func_02068790(int unused, char* obj) {
    int value = *(int*)(obj + 0x8b8);
    return value != 1;
}
