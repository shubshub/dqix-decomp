#include <globaldefs.h>

// USA: func_020e16dc
extern "C" ARM void func_020e16dc(unsigned char* p, int idx, short val) {
    if (idx < 0) return;
    if (idx < 2) {
        *(short*)(p + 0x22 + idx * 2) = val;
    }
}
