#include <globaldefs.h>


extern "C" void func_020d1564(int);
extern "C" void HaltSystem(void);

// USA: func_020d192c
extern "C" ARM void func_020d192c(void) {
    func_020d1564(2);
    HaltSystem();
}
