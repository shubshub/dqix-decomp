#include <globaldefs.h>
#include "NitroSDK/Memory.h"

extern "C" ARM int func_ov031_02236474(void);
extern "C" int func_ov031_022130ac(void);
extern "C" void* func_ov031_0221b9a4(void);
extern "C" void func_ov031_02222bdc(void);
extern "C" ARM void* func_ov031_0223c7c4(int idx);
extern "C" void func_ov031_0223cbbc(int, int);
extern "C" ARM void func_ov031_022274d0(int a, int b);
extern "C" ARM void func_ov031_022274c0(int);
extern "C" void func_ov031_0222e3e8(void);
extern "C" void func_ov031_02233e4c(void);

struct Struct_ov031_02290cd0_3 {
    unsigned char unknown_0_;
    unsigned char pad[3];
    int field4;
};
extern Struct_ov031_02290cd0_3 data_ov031_02290cd0;

// USA: func_ov031_02233ce0
extern "C" ARM void func_ov031_02233ce0(void) {
    char* g = (char*)func_ov031_02236474();
    if (data_ov031_02290cd0.field4 != 0) {
        if (func_ov031_022130ac() == 0) {
            return;
        }
    }
    VectorizedInvertedMemcpy(func_ov031_0221b9a4(), g + 0xf0, 0xe);
    VectorizedInvertedMemcpy(func_ov031_0221b9a4(), g + 0x1f0, 0xe);
    func_ov031_02222bdc();
    func_ov031_0223c7c4(0);
    func_ov031_0223cbbc(0, 0x15);
    if (data_ov031_02290cd0.unknown_0_ == 0) {
        func_ov031_022274d0(0, 1);
        func_ov031_022274c0((int)func_ov031_0222e3e8);
    } else {
        func_ov031_022274d0(0, 1);
        func_ov031_022274c0((int)func_ov031_02233e4c);
    }
}
