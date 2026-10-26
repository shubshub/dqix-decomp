#include <globaldefs.h>
#include "std_library_functions.h"

extern "C" int LinkSession_IsHostOrSolo(void* state);
extern "C" void func_ov017_02195250(void* d, void* buf);

// USA: func_ov017_021cc148
ARM void CopyNameIfActive_021cc148(unsigned char a, unsigned char* src, int unused2, void* d, void* state) {
    if (!LinkSession_IsHostOrSolo(state)) return;
    unsigned char buf[0x10];
    buf[0] = a;
    buf[1] = src[5];
    strcpy((char*)&buf[2], (char*)src + 6);
    func_ov017_02195250(d, buf);
}
