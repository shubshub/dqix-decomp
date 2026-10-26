#include <globaldefs.h>

extern "C" int func_ov031_0223c054(int);
extern "C" ARM int func_ov031_02222ddc(void);
extern "C" void func_ov031_0223c078(int, int, int, int);
extern "C" ARM void func_ov031_022274c0(int);
extern "C" void func_ov031_02234bb8(void);

extern unsigned char data_ov031_02290ce4;

// USA: func_ov031_02234b4c
extern "C" ARM void func_ov031_02234b4c(void) {
    if (func_ov031_0223c054(1) != 0) {
        return;
    }
    func_ov031_02222ddc();
    unsigned char v = data_ov031_02290ce4;
    if ((unsigned char)(v + 0xfe) <= 1) {
        func_ov031_0223c078(3, 1, 1, 8);
    }
    func_ov031_0223c078(3, 0, 0x15, 8);
    func_ov031_022274c0((int)func_ov031_02234bb8);
}
