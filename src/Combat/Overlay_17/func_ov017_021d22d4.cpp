#include <globaldefs.h>
#include "std_library_functions.h"

extern "C" void* LinkMessageQueue_GetInstance(void);
extern "C" void func_0205e330(void* a, void* b, int c);

struct Struct_ov017_021d22d4 {
    unsigned short unknown_0_0_ : 2;
    unsigned short unknown_0_2_ : 14;
};

// USA: func_ov017_021d22d4
extern "C" ARM void func_ov017_021d22d4(unsigned short a0, unsigned short a1, void* a2) {
    void* p = LinkMessageQueue_GetInstance();
    unsigned char buf[0x14];
    Struct_ov017_021d22d4* bits = (Struct_ov017_021d22d4*)(buf + 4);
    buf[0] = 0x9d;
    bits->unknown_0_0_ = a0;
    bits->unknown_0_2_ = a1;

    int len = 0xe;
    if ((unsigned int)(a1 + 0xe) > 0x2e0) {
        len = 0x2e0 - a1;
    }
    if (len >= 0) {
        memcpy((unsigned char*)bits + 2, (unsigned char*)a2 + a1, len);
        func_0205e330(p, buf, 0);
    }
}
