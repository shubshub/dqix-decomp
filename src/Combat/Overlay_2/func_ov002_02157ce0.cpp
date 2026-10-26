#include <globaldefs.h>

extern "C" void func_ov002_02153e90(void*);

// USA: func_ov002_02157ce0
extern "C" ARM void func_ov002_02157ce0(char* p) {
    *(short*)p = 0;
    p[2] = -1;
    p[3] = 0;
    for (int i = 0; i < 4; i++) {
        char* q = p + i;
        q[4] = -1;
        func_ov002_02153e90(p + 8 + i * 6);
        func_ov002_02153e90(p + 0x20 + i * 6);
    }
    *(int*)(p + 0x38) = 0;
}
