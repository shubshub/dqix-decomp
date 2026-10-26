#include <globaldefs.h>

// USA: func_0202630c
extern "C" ARM void func_0202630c(void* obj, int* pos, int margin) {
    if (pos[0] <= margin) {
        pos[0] = margin;
    }
    if (pos[0] >= 0x100000 - margin) {
        pos[0] = 0x100000 - margin;
    }
    if (pos[2] <= margin) {
        pos[2] = margin;
    }
    if (pos[2] >= 0xC0000 - margin) {
        pos[2] = 0xC0000 - margin;
    }
}
