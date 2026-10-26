#include <globaldefs.h>

extern "C" void func_ov017_021ac32c(void* obj);

// USA: func_ov017_021aca00
extern "C" ARM void func_ov017_021aca00(unsigned char* obj) {
    obj[1] = 1;
    func_ov017_021ac32c(obj);
}
