#include <globaldefs.h>
#include "std_library_functions.h"

void* LinkMessageQueue_GetInstance(void);
extern "C" void func_0205e330(void* a, void* b, int c);

struct Struct_ov017_021d22d4 {
    unsigned short unknown_0_0_ : 2;
    unsigned short unknown_0_2_ : 14;
};

// USA: func_ov017_021d22d4
extern "C" ARM void func_ov017_021d22d4(unsigned short a0, unsigned short a1, void* a2) {
    void* p = LinkMessageQueue_GetInstance();
    unsigned char buf[0x14];
    Bits021d22d4* bits = (Bits021d22d4*)(buf + 4);
    buf[0] = 0x9d;
    bits->lo2 = a0;
    bits->hi14 = a1;

    int var3 = 0xe;
    if ((unsigned int)(arg1 + 0xe) > 0x2e0) {
        var3 = 0x2e0 - arg1;
    }
    if (var3 >= 0) {
        memcpy((unsigned char*)var2 + 2, (unsigned char*)arg2 + arg1, var3);
        func_0205e330(var0, var1, 0);
    }
}
