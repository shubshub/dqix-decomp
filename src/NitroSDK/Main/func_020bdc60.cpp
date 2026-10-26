#include <globaldefs.h>
extern "C" void func_020d2680(unsigned int);

extern "C" int func_020d26ec(void);
extern "C" void func_020d24c4(int);

// USA: func_020bdc60
extern "C" ARM void func_020bdc60() {
    int ctx = func_020d26ec();
    func_020d24c4(1);
    func_020d2680((unsigned int)(ctx));
}
