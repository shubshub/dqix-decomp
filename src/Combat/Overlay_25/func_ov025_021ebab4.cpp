#include <globaldefs.h>

extern "C" void func_ov025_021ebb24(void* entry);
extern "C" void* func_ov000_02160130(void);
extern "C" void func_ov025_021dcd5c(void* obj);
extern "C" void func_ov025_021dcd98(char* obj);

// USA: func_ov025_021ebab4
extern "C" ARM void func_ov025_021ebab4(char* obj) {
    for (int i = 0; i < 0xc; i++) {
        func_ov025_021ebb24(obj + (i << 6));
    }
    obj[0x300] = 0;
    *(unsigned short*)(obj + 0x302) = 0;
    *(unsigned short*)(obj + 0x304) = 0;
    obj[0x301] = 0;
    obj[0x306] = 0;
    void* work = func_ov000_02160130();
    func_ov025_021dcd5c(work);
    func_ov025_021dcd98((char*)work);
    *(int*)(obj + 0x308) = 0;
    *(int*)(obj + 0x30c) = 0;
    obj[0x310] = 1;
    obj[0x311] = 0;
}
