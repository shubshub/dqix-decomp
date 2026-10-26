#include <globaldefs.h>

// USA: func_ov025_021ed5f0
#pragma optimize_for_size off
extern "C" ARM void func_ov025_021ed5f0(char* obj, int val, int type, int val2) {
    if (type >= 6) return;
    if (*(unsigned char*)(obj + 0x151) >= 0x10) return;
    unsigned char count = *(unsigned char*)(obj + 0x151);
    *(int*)(obj + 0xf0 + count * 4) = val;
    count = *(unsigned char*)(obj + 0x151);
    *(unsigned char*)(obj + 0x130 + count) = type;
    count = *(unsigned char*)(obj + 0x151);
    *(unsigned char*)(obj + 0x140 + count) = val2;
    count = *(unsigned char*)(obj + 0x151);
    *(unsigned char*)(obj + 0x151) = count + 1;
}
