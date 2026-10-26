#include <globaldefs.h>

extern "C" void func_ov017_021c1394(void* obj);
extern "C" void func_ov017_021c1264(int flag);

// USA: func_ov017_021c168c
extern "C" ARM void func_ov017_021c168c(void* obj) {
    func_ov017_021c1394(obj);
    *((unsigned char*)obj + 1) = 1;
    func_ov017_021c1264(1);
}
