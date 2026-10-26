#include <globaldefs.h>

// USA: func_020b035c
extern "C" ARM void func_020b035c(char* base, int index, int value) {
    *(int*)(base + (index << 2) + 0x8) = value;
}
