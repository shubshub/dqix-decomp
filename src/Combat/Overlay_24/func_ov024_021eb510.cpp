#include <globaldefs.h>
#include "std_library_functions.h"

// USA: func_ov024_021eb510
extern "C" ARM void func_ov024_021eb510(void* obj) {
    unsigned char* p = (unsigned char*)obj;
    *(int*)(p+0x10) = 0;
    *(unsigned char*)(p+0x6c) = 0;
    *(int*)(p+0x14) = 0;
    *(short*)(p+0x44) = -1;
    *(int*)(p+0x18) = 0;
    *(int*)(p+0x4) = 0;
    *(int*)(p+0x8) = 0;
    *(int*)(p+0xc) = 0;
    *(unsigned char*)(p+0x6e) = 0;
    *(unsigned char*)(p+0x6f) = 1;
    *(float*)(p+0x1c) = 1.0f;
    *(unsigned char*)(p+0x71) = 0;
    *(unsigned char*)(p+0x72) = 0;
    *(unsigned char*)(p+0x73) = 0;
    *(unsigned char*)(p+0x47) = 0;
    *(unsigned char*)(p+0x76) = 0;
    *(unsigned char*)(p+0x78) = 0;
    *(unsigned char*)(p+0x79) = 0;
    *(unsigned char*)(p+0x77) = 0;
    *(unsigned char*)(p+0x7a) = 0;
    memset(p+0x48, 0, 0x20);
    *(int*)(p+0x68) = 0;
    memset(p+0x20, -1, 8);
    memset(p+0x28, -1, 0x10);
    memset(p+0x38, 0, 4);
    memset(p+0x3c, 0, 8);
}
