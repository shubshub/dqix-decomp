#include <globaldefs.h>

extern int MessageSystem_GetInstance();
extern "C" void func_020439b0(int a, int flag);

// USA: func_ov017_021adc44
ARM void ClearGlobalField_021adc44_021adc44(void*) {
    func_020439b0(MessageSystem_GetInstance(), 0);
}
