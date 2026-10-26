#include <globaldefs.h>

extern "C" void func_ov017_021adb1c(void* obj);

// USA: func_ov017_021adb08
extern "C" ARM void func_ov017_021adb08(unsigned char* obj) {
    obj[1] = 1;
    func_ov017_021adb1c(obj);
}
