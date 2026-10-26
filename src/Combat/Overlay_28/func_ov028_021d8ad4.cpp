#include <globaldefs.h>
#include "std_library_functions.h"

extern "C" void func_ov028_021d8a40(void* local);

// USA: func_ov028_021d8ad4
extern "C" ARM void func_ov028_021d8ad4(void* obj, char* buf) {
    unsigned int local[0x38];
    char* p = (char*)obj;
    int val = *(int*)(p + 0x8);
    if ((unsigned int)(val >> 12) < 0x20) {
        return;
    }
    func_ov028_021d8a40(local);
    int diff = *(int*)(p + 0x0) - *(int*)(p + 0x8);
    diff = (diff >> 12) & 0xff;
    diff = diff >> 3;
    memset(buf + (diff << 10), 0x11111111, 0x1000);
    *(int*)(p + 0x8) -= 0x20000;
    *(unsigned char*)(p + 0xe) = 1;
}
