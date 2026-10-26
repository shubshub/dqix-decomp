#include <globaldefs.h>

extern "C" void func_ov031_02234570(void);
extern "C" void func_ov031_02223998(int idx);
extern "C" void func_ov031_0222336c(int, int, int);
extern "C" int func_ov031_02223518(void *obj);
extern "C" void func_ov031_022235a0(void *arg);
extern "C" void func_ov031_02234618(void);
extern "C" ARM void func_ov031_022274c0(int v);

struct Struct_ov031_02290ce0 { unsigned char flag; };
extern Struct_ov031_02290ce0 data_ov031_02290ce0;

// USA: func_ov031_02234520
extern "C" ARM void func_ov031_02234520(void) {
    data_ov031_02290ce0.flag = 0;
    func_ov031_02234570();
    func_ov031_02223998(8);
    func_ov031_0222336c(0x38, 0x38 - 0x39, 0);
    func_ov031_02223518((void *)1);
    func_ov031_022235a0((void *)0x27);
    func_ov031_022274c0((int)func_ov031_02234618);
}
