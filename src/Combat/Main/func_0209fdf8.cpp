#include <globaldefs.h>

extern "C" int MessageSystem_GetInstance();
extern "C" void func_020457e0(void);

// USA: func_0209fdf8
extern "C" ARM void func_0209fdf8(void) {
    MessageSystem_GetInstance();
    func_020457e0();
}
