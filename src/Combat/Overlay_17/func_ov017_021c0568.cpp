#include <globaldefs.h>

extern "C" void func_ov017_021c0364(void* obj);

// USA: func_ov017_021c0568
extern "C" ARM void func_ov017_021c0568(unsigned char* obj) {
    func_ov017_021c0364(obj);
    obj[1] = 1;
}
