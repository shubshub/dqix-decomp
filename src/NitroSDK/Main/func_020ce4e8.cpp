#include <globaldefs.h>

unsigned int DisableIRQInterrupts(void);
unsigned int SetIRQInterruptState(int mask);
extern "C" int func_020ce128(void);
extern "C" void func_020ce870(int cmd);

struct Struct_021117ec_6 {
    char pad[0x20];
    int f20;
    int f24;
    int f28;
};
extern struct Struct_021117ec_6 data_021117ec;

// USA: func_020ce4e8
extern "C" ARM int func_020ce4e8(int a0, int a1, int a2, int a3, int a4) {
    int var0 = DisableIRQInterrupts();
    if (func_020ce128() == 0) {
        SetIRQInterruptState(var0);
        return 1;
    }
    int cmd = (a0 & 0xff) | 0x2006100;
    data_021117ec.f20 = a3;
    data_021117ec.f24 = a4;
    data_021117ec.f28 = a2;
    func_020ce870(cmd);
    func_020ce870(0x1010000 | (a1 & 0xffff));
    SetIRQInterruptState(var0);
    return 0;
}
