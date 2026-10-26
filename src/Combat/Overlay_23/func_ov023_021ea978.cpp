#include <globaldefs.h>

extern "C" void* Zone3D_GetInstance(void);
extern "C" void func_ov017_021d6134(void*, short);

// USA: func_ov023_021ea978
extern "C" ARM int func_ov023_021ea978(void* obj) {
    short v = *(short*)Zone3D_GetInstance();
    func_ov017_021d6134(obj, (short)(v - v % 100));
    return 1;
}
