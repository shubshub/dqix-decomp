#include <globaldefs.h>

extern "C" void func_ov031_0222b168(void);
extern "C" void func_ov031_0222b1a0(void);
extern "C" void func_ov031_0222b1a4(void);
extern "C" int func_ov031_02226f68(void);
extern "C" void* func_ov031_022368e0(void);
extern "C" int func_ov031_02237b2c(int, int, int, int, int);
extern "C" int func_ov031_02236878(int);
extern "C" void func_ov031_02222e98(void);
extern "C" ARM void func_ov031_022274c0(int);
extern "C" void func_ov031_0222b3d4(void);
extern "C" ARM void func_ov031_0222b388(void);
extern "C" ARM int func_ov031_0223e2e0(int, void*);

struct Struct_ov031_02290c80 { unsigned char field0; unsigned char pad[3]; int field4; };
extern Struct_ov031_02290c80 data_ov031_02290c80;

// USA: func_ov031_0222b094
extern "C" ARM void func_ov031_0222b094(void) {
    func_ov031_0222b168();
    func_ov031_0222b1a0();
    func_ov031_0222b1a4();
    int state = func_ov031_02226f68();
    if (state == 0) return;
    if (state == 1) goto state1;
    if (state == 2) goto state2;
    return;
state1:
    if (data_ov031_02290c80.field4 == 0) return;
    data_ov031_02290c80.field0 = 1;
    func_ov031_0223e2e0(1, (void*)data_ov031_02290c80.field4);
    data_ov031_02290c80.field4 = 0;
    func_ov031_022274c0((int)func_ov031_0222b3d4);
    return;
state2:
    if (data_ov031_02290c80.field4 == 0) return;
    func_ov031_022368e0();
    func_ov031_02237b2c(0xc, 1, 1, -1, 0);
    func_ov031_02236878(9);
    func_ov031_02222e98();
    func_ov031_0223e2e0(1, (void*)data_ov031_02290c80.field4);
    data_ov031_02290c80.field4 = 0;
    func_ov031_022274c0((int)func_ov031_0222b388);
    return;
}
