#include <globaldefs.h>

// USA: func_ov011_02184a24
extern "C" ARM void func_ov011_02184a24(void* p, int a, int b) {
    *(int*)((char*)p + 0x1b4) = a;
    *(int*)((char*)p + 0x1b8) = b;
}
