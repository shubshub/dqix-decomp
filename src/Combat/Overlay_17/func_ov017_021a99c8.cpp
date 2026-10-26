#include <globaldefs.h>

extern "C" void func_ov017_021a9714(void* obj);

// USA: func_ov017_021a99c8
extern "C" ARM void func_ov017_021a99c8(unsigned char* obj) {
    obj[1] = 1;
    func_ov017_021a9714(obj);
}
