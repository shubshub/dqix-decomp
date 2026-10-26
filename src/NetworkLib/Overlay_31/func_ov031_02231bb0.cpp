#include <globaldefs.h>

extern unsigned char data_ov031_02290cb8;
extern "C" void func_ov031_02231c0c(void);
extern "C" void func_ov031_022239f4(void);
extern "C" void func_ov031_0222336c(int, int, int);
extern "C" int func_ov031_02223518(void*);
extern "C" void func_ov031_022235a0(int);
extern "C" void func_ov031_02222b0c(int);
extern "C" void func_ov031_02236878(int);
extern "C" void func_ov031_022274c0(int);
extern "C" void func_ov031_02231cb4(void);

// USA: func_ov031_02231bb0
extern "C" ARM void func_ov031_02231bb0(void) {
    data_ov031_02290cb8 = 0;
    func_ov031_02231c0c();
    func_ov031_022239f4();
    int a = 0x37;
    func_ov031_0222336c(a, a - 0x38, 0);
    func_ov031_02223518((void*)2);
    func_ov031_022235a0(0x24);
    func_ov031_02222b0c(0);
    func_ov031_02236878(0xb);
    func_ov031_022274c0((int)func_ov031_02231cb4);
}
