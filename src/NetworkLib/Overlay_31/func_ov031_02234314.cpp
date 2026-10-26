#include <globaldefs.h>

extern unsigned char data_ov031_02290cdc;
extern "C" void func_ov031_02234354(void);
extern "C" void func_ov031_02223998(int);
extern "C" void func_ov031_022235a0(int);
extern "C" void func_ov031_02236878(int);
extern "C" void func_ov031_022274c0(int v);
extern "C" void func_ov031_022343d4(void);

// USA: func_ov031_02234314
extern "C" ARM void func_ov031_02234314(void) {
    data_ov031_02290cdc = 0;
    func_ov031_02234354();
    func_ov031_02223998(8);
    func_ov031_022235a0(0x29);
    func_ov031_02236878(0x10);
    func_ov031_022274c0((int)func_ov031_022343d4);
}
