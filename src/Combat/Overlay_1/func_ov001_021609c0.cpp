#include <globaldefs.h>

extern "C" int MessageSystem_GetInstance();
extern "C" int func_020457e0();
extern "C" void func_ov017_021d6134(void*, unsigned int);

// USA: func_ov001_021609c0
extern "C" ARM int func_ov001_021609c0(void* self) {
    MessageSystem_GetInstance();
    int v = func_020457e0();
    func_ov017_021d6134(self, v);
    return 1;
}
