#include <globaldefs.h>
#include "std_library_functions.h"


extern "C" void* LinkMessageQueue_GetInstance(void);
extern "C" void* Scenario_GetInstance(void* obj);
extern "C" void func_0205e330(void* a, void* b, int c);

struct Struct_ov017_021cdc24 {
    unsigned short unknown_0_0_ : 2;
    unsigned short unknown_0_2_ : 14;
};

// USA: func_ov017_021cdc24
extern "C" ARM void func_ov017_021cdc24(int a0, int a1) {
    void* p = LinkMessageQueue_GetInstance();
    unsigned char buf[0x14];
    Struct_ov017_021cdc24* bits = (Struct_ov017_021cdc24*)(buf + 4);
    bits->unknown_0_0_ = a0;
    buf[0] = 0x92;
    bits->unknown_0_2_ = a1;

    unsigned char* result = (unsigned char*)Scenario_GetInstance(p);
    int len = 0xe;
    if ((unsigned int)(a1 + 0xe) > 0xfd) {
        len = 0xfd - a1;
    }
    if (len >= 0) {
        memcpy((unsigned char*)bits + 2, result + a1, len);
        func_0205e330(p, buf, 0);
    }
}
