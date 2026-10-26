#include <globaldefs.h>

// USA: func_ov023_021eb414
extern "C" ARM void func_ov023_021eb414(char* obj) {
    if (*(unsigned char*)(obj + 0x44a) != 0) return;
    *(unsigned char*)(obj + 0x44a) = 1;
    *(unsigned char*)(obj + 0x431) = 2;
    *(unsigned char*)(obj + 0x432) = 0;
}
