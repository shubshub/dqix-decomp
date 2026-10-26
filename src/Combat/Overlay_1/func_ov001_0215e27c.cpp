#include <globaldefs.h>

extern "C" void func_ov001_021537a0(int* obj);
extern int data_ov001_021658d8;
extern unsigned char data_ov001_021658b8[];

// USA: func_ov001_0215e27c
extern "C" ARM int func_ov001_0215e27c(void) {
    func_ov001_021537a0(&data_ov001_021658d8);
    data_ov001_021658b8[0x8c] = 0;
    return 1;
}
