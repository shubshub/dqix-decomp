#include <globaldefs.h>
#include "NitroSDK/ProcessorContext.h"


extern "C" void* func_ov031_0223cf4c(unsigned int len, int align);
extern "C" void HaltSystem(void);
extern "C" int func_ov031_02222928(int, int, void*, void*, void*, int);
struct Struct_ov031_02227cb0;
extern "C" ARM void func_ov031_02227cb0(Struct_ov031_02227cb0* src);
extern "C" ARM int func_ov031_02227cc8(int a);
extern "C" ARM unsigned int func_ov031_02227cd8(void* arg0);

extern void* data_ov031_02290c48;

// USA: func_ov031_02227b38
extern "C" ARM void func_ov031_02227b38(void) {
    unsigned int len = 0xc;
    void* p = func_ov031_0223cf4c(len, len - 0x10);
    data_ov031_02290c48 = p;
    int r = func_ov031_02222928(0xf, 0x40, (void*)func_ov031_02227cb0, (void*)func_ov031_02227cc8, (void*)func_ov031_02227cd8, 0x800);
    if (r != 1) {
        HaltSystem();
    }
    SleepCurrentContext(0xa);
}
