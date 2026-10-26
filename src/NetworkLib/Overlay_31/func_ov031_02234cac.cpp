#include <globaldefs.h>

extern "C" void* func_ov031_022368e0();
extern "C" int func_ov031_02236878(int index);
extern "C" void func_ov031_02237b2c(int, int, int, int, int);
extern "C" void func_ov031_02222e98(void);
extern "C" void func_ov031_022376e4(int val);
extern "C" void func_ov031_022274c0(int);
extern "C" void func_ov031_02234d98(void);
extern "C" void func_ov031_02234b2c(void);
extern "C" void func_ov031_02234de4(void);

extern unsigned char data_ov031_02290ce4;

// USA: func_ov031_02234cac
extern "C" ARM void func_ov031_02234cac(int mode) {
    if (data_ov031_02290ce4 != 0) {
        return;
    }
    switch (mode) {
    case 0:
        data_ov031_02290ce4 = 3;
        func_ov031_022368e0();
        func_ov031_02236878(0x12);
        func_ov031_02237b2c(0x10, 1, 1, -1, 0);
        func_ov031_02222e98();
        func_ov031_022274c0((int)func_ov031_02234d98);
        break;
    case 1:
        data_ov031_02290ce4 = 1;
        func_ov031_022368e0();
        func_ov031_022274c0((int)func_ov031_02234b2c);
        break;
    case 2:
        func_ov031_022368e0();
        func_ov031_022376e4(0);
        func_ov031_02237b2c(0x11, 0, 1, -1, 0);
        func_ov031_02222e98();
        func_ov031_022274c0((int)func_ov031_02234de4);
        break;
    case 3:
        data_ov031_02290ce4 = 2;
        func_ov031_022368e0();
        func_ov031_02236878(9);
        func_ov031_022274c0((int)func_ov031_02234b2c);
        break;
    }
}
