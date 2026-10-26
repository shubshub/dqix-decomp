#include <globaldefs.h>

extern unsigned char data_ov031_02290cd8;
extern "C" ARM void func_ov031_02227520(int* a, int* b);
extern "C" ARM unsigned int func_ov031_02227558(void);
extern "C" ARM void func_ov031_022274c0(int v);
extern "C" void func_ov031_02227ce4(void);
extern "C" void func_ov031_02233f54(void);

// USA: func_ov031_02234050
extern "C" ARM void func_ov031_02234050(void) {
    unsigned char c = ++data_ov031_02290cd8;
    if (c < 0xb4) return;

    int idx;
    func_ov031_02227520(NULL, &idx);
    unsigned int v = func_ov031_02227558();
    if (v != 0 && v == 1 && idx != 0) {
        func_ov031_022274c0((int)func_ov031_02227ce4);
    } else {
        func_ov031_022274c0((int)func_ov031_02233f54);
    }
}
