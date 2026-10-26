#include <globaldefs.h>

extern "C" int func_020d22f4(int id);
extern "C" void func_020bc2f0(void);
extern "C" void func_020bed10(void);
extern "C" void func_020d24c4(int a);
extern "C" void func_020bceb4(void);

// USA: func_020bbd9c
extern "C" ARM void func_020bbd9c(void) {
    while (func_020d22f4(0) != 0) {
    }
    func_020bc2f0();
    func_020bceb4();
    func_020bed10();
    func_020d24c4(0);
}
