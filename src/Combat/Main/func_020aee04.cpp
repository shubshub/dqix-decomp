#include <globaldefs.h>

extern "C" unsigned short* Zone3D_GetInstance(void);
extern "C" void func_020ae694(int, int, unsigned short);
extern "C" void func_020ae4ec(int param0, int param1);

// USA: func_020aee04
extern "C" ARM void func_020aee04(int mode, int value) {
    if (*Zone3D_GetInstance() != 0x1cea) return;
    if (mode == 1) {
        int key = 0x4e;
        for (; key <= 0x58; key++) {
            func_020ae694((unsigned char)value, 0, key);
        }
        func_020ae4ec(0x47, value != 0);
    } else if (mode == 0) {
        int key = 0x37;
        for (; key <= 0x4b; key++) {
            func_020ae694((unsigned char)value, 0, key);
        }
        func_020ae4ec(0x48, value != 0);
    }
}
