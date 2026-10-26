#include <globaldefs.h>

// USA: func_ov002_02168c00
extern "C" ARM int func_ov002_02168c00(unsigned char* obj) {
    int a = (*(int*)(obj + 0x60) == -1);
    int b = (*(int*)(obj + 0x64) == -1);
    return (a & b) != 0;
}
