#include <globaldefs.h>

extern "C" int func_02003ddc(int a);
extern "C" void func_0200159c(int a);

extern char data_020f2e60[];

// USA: func_02001578
extern "C" ARM void func_02001578(void) {
    func_02003ddc(1);
    *(int*)(data_020f2e60 + 0xc) = 1;
    func_0200159c(1);
}
