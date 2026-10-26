#include <globaldefs.h>

// USA: func_02098210
extern "C" ARM int func_02098210(int a, int id) {
    int base = 0xc3b5;
    return id == base || id == base + 0x64 || id == base + 0xc8 || id == base + 0x12c;
}
