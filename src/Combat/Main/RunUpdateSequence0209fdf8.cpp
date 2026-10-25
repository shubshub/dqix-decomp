#include <globaldefs.h>

int MessageSystem_GetInstance();
extern "C" void func_020457e0(void);

// USA: func_0209fdf8
ARM void RunUpdateSequence0209fdf8(void) {
    MessageSystem_GetInstance();
    func_020457e0();
}
