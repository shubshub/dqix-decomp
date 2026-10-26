#include <globaldefs.h>

// USA: func_ov025_021ed2a0
extern "C" ARM void func_ov025_021ed2a0(char* obj) {
    if (*(unsigned char*)(obj + 0x151) == 0) {
        return;
    }
    *(unsigned char*)(obj + 0x151) -= 1;
    for (int i = 0; i < *(unsigned char*)(obj + 0x151); i++) {
        *(int*)(obj + 0xf0 + i * 4) = *(int*)(obj + 0xf0 + (i + 1) * 4);
        *(unsigned char*)(obj + 0x130 + i) = *(unsigned char*)(obj + 0x130 + (i + 1));
    }
}
